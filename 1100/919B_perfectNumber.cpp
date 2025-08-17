#include <iostream>

using namespace std;

int sum_digits(int x) {
    int s = 0;
    while (x) { s += x % 10; x /= 10; }
    return s;
}

int nth_perfect(int n) {
    int x = 19 + (n - 1) * 9;
    while (sum_digits(x) != 10) x += 9;
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << nth_perfect(n) << '\n';
}
