#include <iostream>
#include <vector>

int main() {
    size_t n; std::cin >> n;
    std::vector<std::vector<int>> v;
    for (std::size_t i = 0; i < n; ++i) {
        int a, b, c;
        std::cin >> a >> b >> c;
        v.push_back({a, b, c});
    }
    int ans_1, ans_2, ans_3;
    for (std::size_t i = 0; i < n; ++i) {
        ans_1 += v[i][0];
        ans_2 += v[i][1];
        ans_3 += v[i][2];
    }
    if (ans_1 != 0 || ans_2 != 0 || ans_3 != 0) {
        std::cout << "NO";
    } else {
        std::cout << "YES";
    }
    return 0;
}
