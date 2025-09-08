#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    size_t n;
    unsigned long k;

    while (t--) {
        cin >> n >> k;
        vector<unsigned long> a(n);
        for (auto &e : a) cin >> e;

        if (n == 1) {
            if (a[0] == 1) a[0] += k;
        } else {
            for (size_t i = 0; i < n; ++i) {
                if (k <= 2) while ((a[i] % (k + 1)) != 0) a[i] += k;
                else a[i] += (k - 1 - (a[i] % (k - 1))) * k;
            }
        }

        for (size_t i = 0; i < n; ++i) cout << a[i] << ' ';
        cout << '\n';
    }

    return 0;
}