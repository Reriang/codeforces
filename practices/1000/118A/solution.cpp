#include <cctype>
#include <iostream>
#include <string>

int main() {
    const std::string vowels ("aoyeui");
    std::string input, ans;
    std::cin >> input;

    for (char c : input) {
        bool vflag { false };
        c = std::tolower(static_cast<unsigned char> (c));
        for (char vowel : vowels) {
            if (c == vowel) {
                vflag = true;
                break;
            }
        }
        if (vflag == false) {
            ans.append(std::string { c });
        }
    }
    for (std::size_t i = 0; i < ans.length(); i += 2) {
        std::string prefixed = {'.', ans.at(i)}; 
        ans.replace(i, 1, prefixed);
    }
    std::cout << ans;

    return 0;
}
