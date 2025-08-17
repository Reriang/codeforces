#include <algorithm>
#include <iostream>

int main() {
    long long int n, m, a;
    long long int width, height;
    long long int ans;
    std::cin >> n >> m >> a;
    int minimum = std::min(n, m);
    int maximum = std::max(n, m);
    if (minimum < a) {
        std::cout << 1;
    } else if (minimum == a) {
        width = (maximum % a == 0) ? maximum / a : maximum / a + 1;
        std::cout << width;
    } else {
        width = (n % a == 0) ? n / a : n / a + 1;
        height = (m % a == 0) ? m / a : m / a + 1;
        ans = width * height;
        std::cout << ans;
    }
    return 0;
}
