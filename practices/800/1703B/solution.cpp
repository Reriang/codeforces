/*
 1703B. ICPC Balloons
*/

#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string input;
        std::cin >> input;
        int scores { 0 };
        std::string visited;
        for (char c : input) {
            if (visited.find(c) != std::string::npos) {
                scores += 1;
            } else {
                visited += c;
                scores += 2;
            }
        }
        std::cout << scores << '\n';
    }
    return 0;
}
