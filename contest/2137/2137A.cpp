#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int k, x;
        cin >> k >> x;
        while (k--) {
            if (x % 2 == 0 && (x - 1) % 3 == 0) {
                x -= 1;
                x /= 3;
            } else {
                x *= 2;
            }
        }
        cout << x << '\n';
    }
    return 0;
}
