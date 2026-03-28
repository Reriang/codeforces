#include <iostream>
#include <string>

int main() {
    const std::string hello { "hello" };
    std::string input;
    std::cin >> input;
    bool contain { false };

    std::size_t index = 0;

    for (char c : hello) {
        while (index < input.length()) {
            if (c == input.at(index) && c == 'o') {
                std::cout << "YES";
                return 0;
            } else if (c == input.at(index)) {
                index++;
                break;
            } else {
                index++;
                continue;
            }
        }
    }

    std::cout << "NO";
    return 0;
}
