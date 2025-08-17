#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v;
    for (std::size_t index { 0 }; index < n; ++index) {
        int temp;
        std::cin >> temp;
        v.push_back(temp);
    }
    for (int num : v) {
        if (num % 4 == 0) {
            std::cout << "Bob" << std::endl;
        } else {
            std::cout << "Alice" << std::endl;
        }
    }
    return 0;
}
