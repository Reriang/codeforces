#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cin >> input;

    bool lock = true;
    if (input.size() == 1) 
        lock = true;
    
    for (size_t i = 1; i < input.size(); ++i) {
        if (input[i] > 91) {
            lock = false;
            break;
        }
    }
    if (lock) {
        for (size_t i = 0; i < input.size(); ++i) {
            if (input[i] < 91) input[i] += 32;
            else input[i] -= 32;
        }
    }
    cout << input << '\n';

    return 0;
}
