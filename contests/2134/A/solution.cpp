#include <iostream>
using namespace std;

int main()
{
    int t;
    unsigned long n, a, b;

    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        if (n % 2 == b % 2) {
            if (b >= a || a % 2 == b % 2) 
                cout << "YES\n";
            else
                cout << "NO\n";
        } else
            cout << "NO\n";
    }

    return 0;
}
