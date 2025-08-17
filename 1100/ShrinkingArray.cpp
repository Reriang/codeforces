/*
 Codeforces 2112B. Shrinking Array
*/
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

bool isWithinRange(long value, long bound1, long bound2) {
    long long low = std::min(bound1, bound2);
    long long high = std::max(bound1, bound2);
    return value >= low && value <= high;
}

bool isGood(std::vector<long long>& arr) {
    for (std::size_t i = 1; i < arr.size(); ++i) {
        if (abs(arr[i] - arr[i - 1]) <= 1)
            return true;
    }
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<long long> a(n);
        for (auto &x: a) std::cin >> x;

        if (isGood(a)) {
            std::cout << 0 << '\n';
            continue;
        }

        bool oneRemoveWorks = false;
        for (std::size_t i = 0; i < n; ++i) {
            std::vector<long long> temp;
            for (std::size_t j = 0; j < n; ++j) {
                if (j != i) temp.push_back(a[j]);
            }
            if (isGood(temp)) {
                oneRemoveWorks = true;
                break;
            }
        }
        if (oneRemoveWorks)
            std::cout << 1 << '\n';
        else 
            std::cout << -1 << '\n';
    }

    return 0;
}