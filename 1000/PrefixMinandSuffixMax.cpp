#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::size_t n;
        std::cin >> n;
        std::vector<int> a(n);
        for (std::size_t i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        std::vector<int> prefixMin(n);
        prefixMin[0] = a[0];
        for (std::size_t j = 1; j < n; ++j) {
            prefixMin[j] = std::min(prefixMin[j - 1], a[j]);
        }

        std::vector<int> suffixMax(n);
        suffixMax[n - 1] = a[n - 1];
        for (std::size_t j = n - 2; j != 0; --j) {
            suffixMax[j] = std::max(suffixMax[j + 1], a[j]);
        }

        for (std::size_t i = 0; i < n; ++i) {
            if (a[i] == prefixMin[i] || a[i] == suffixMax[i]) {
                std::cout << '1';
            } else {
                std::cout << '0';
            }
        }

        std::cout << '\n';
    }

    return 0;
}