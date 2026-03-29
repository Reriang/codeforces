#include <iostream>
#include <vector>
using namespace std;

int main() {
    size_t n; cin >> n;

    vector<int> force{ 0, 0, 0 };
    while (n--) {
        int a, b, c; cin >> a >> b >> c;
        force[0] += a;
        force[1] += b;
        force[2] += c;
    }
    if (force[0] == 0 && force[1] == 0 && force[2] == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
