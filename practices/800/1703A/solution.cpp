#include <iostream>
#include <algorithm>
#include <string>

int main() {
    int t;
    std::cin >> t;
    std::string yes { "yes" };
    while (t--) {
        std::string input;
        std::cin >> input;
        for (char &c : input) {
            c = tolower(c);
        }
        if (input == yes) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
