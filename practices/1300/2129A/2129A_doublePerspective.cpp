#include <iostream>
#include <map>
#include <vector>
using namespace std;

/*
Codeforces: 2129A. Double Perspective
Link: https://codeforces.com/problemset/problem/2129/A
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        size_t n; cin >> n;
        map<size_t, vector<size_t>> ids;
        while (n--) {
            size_t a, b; cin >> a >> b;
            if (ids.count(a) > 0)
                ids[a].push_back(b);
            else
                ids[a] = { b };
        }
        cout << "Total: " << ids.size() << " in ids.\n";
        cout << "Elements in ids: \n";
        for (auto [key, value] : ids) {
            cout << "Key: " << key << '\n' << "Values: ";
            for (auto s : value)
                cout << s << ' ';
            cout << '\n';
        }
        cout << "The size of ids is: " << ids.size() << '\n';
    }
    return 0;
}
