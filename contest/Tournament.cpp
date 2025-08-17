#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int cases;
    std::cin >> cases;
    for (std::size_t index { 0 }; index < cases; ++index) {
        int n, j, k;
        std::cin >> n >> j >> k;
        std::vector<int> players;
        while (n > 0) {
            int temp;
            std::cin >> temp;
            players.push_back(temp);
            n--;
        }
        int strength { players.at(j-1) };
        std::sort(players.begin(), players.end(), std::greater<int>());

        int bigger { 0 };
        for (int value : players) {
            if (value > strength) {
                bigger += 1;
            } else {
                break;
            }
        }

        int unique_bigger { 0 };
        auto last = std::unique(players.begin(), players.end());
        players.erase(last, players.end());
        for (int value : players) {
            if (value > strength) {
                unique_bigger += 1;
            } else {
                break;
            }
        }
        int agreeable { bigger - unique_bigger };
        if (unique_bigger + agreeable <= k) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}