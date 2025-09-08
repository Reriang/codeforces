#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        size_t n;
        cin >> n;
        vector<size_t> p;
        size_t a;
        for (size_t i = 0; i < n; ++i) {
            cin >> a;
            p.push_back(a);
        }
        for (auto e : p) {
            e -= 1;
            cout << n - e << ' ';
        }
        cout << '\n';
    }
    return 0;
}
