#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        vector<long long> sums;
        for (long long i = 1; i * i <= b; ++i) {
            long long result = 0;
            if (b % i == 0) {
                result += a * i;
                result += b / i;
                if (result % 2 == 0) sums.push_back(result);
                if (i * i != b) {
                    result = 1;
                    result = b / i;
                    result *= a;
                    result += i;
                    if (result % 2 == 0) sums.push_back(result);
                }
            }
        }
        sort(sums.begin(), sums.end(), greater<long long>());
        if (sums.size() > 0)
            cout << sums[0] << ' ';
        else 
            cout << -1 << ' ';
        cout << '\n';
    }
    return 0;
}
