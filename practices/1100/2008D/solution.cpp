#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

using namespace std;

void solution(size_t n, vector<size_t> &permutation, string &black) {
    vector<bool> visited(n, false);
    int answer;
    for (auto num : permutation) {
        answer = 0;
        visited.assign(n, false);
        while (!visited[num - 1]) {
            visited[num - 1] = true;
            if (black.at(num - 1) == '0')
                answer += 1;
            num = permutation[num - 1];
        }
        std::cout << answer << ' ';
    }
    std::cout << '\n';
}

void better_solution(size_t n, vector<size_t> &permutation, string &black) {
    vector<bool> visited(n, false);
    map<size_t, shared_ptr<int>> reach;
    for (auto num : permutation) {
        if (visited[num - 1])
            continue;
        auto sharedAnswer = make_shared<int>(0);
        while (!visited[num - 1]) {
            visited[num - 1] = true;
            reach[num] = sharedAnswer;
            if (black.at(num - 1) == '0')
                (*reach[num])++;
            num = permutation[num - 1];
        }
    }
    for (auto num : permutation) 
        cout << *reach[num] << ' ';
    cout << '\n';
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        size_t n;
        cin >> n;

        vector<size_t> permutation(n);
        string blackOrNot;
        for (auto &e : permutation) 
            cin >> e;
        cin >> blackOrNot;

        better_solution(n, permutation, blackOrNot);
        cout << '\n';
    }
    return 0;
}
