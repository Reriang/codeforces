#include <bits/stdc++.h>
using namespace std;

// 0/1 Knapsack Problem: https://www.geeksforgeeks.org/dsa/0-1-knapsack-problem-dp-10/


// Top-Down DP (Memoization), O(n x W) Time and O(n x W) Space
int knapsackRec(size_t W, size_t n, vector<int> &profit, vector<size_t> &weight, vector<vector<int>> &memo) {
    if (n == 0 || W == 0)
        return 0;

    if (memo[n][W] != -1)
        return memo[n][W];

    int pick = 0;

    if (weight[n - 1] <= W)
        pick = profit[n - 1] + knapsackRec(W - weight[n - 1], n - 1, profit, weight, memo);

    int notPick = knapsackRec(W, n - 1, profit, weight, memo);

    return memo[n][W] = max(pick, notPick);
}

int knapsackTopDown(size_t W, size_t n, vector<int> &profit, vector<size_t> &weight) {
    vector<vector<int>> memo(n + 1, vector<int>(W + 1, -1));

    return knapsackRec(W, n, profit, weight, memo);
}


// Bottom-Up DP (Tabulation), O(n x W) Time and O(n x W) Space
int knapsackBottomUp(size_t W, size_t n, vector<int> &profit, vector<size_t> &weight) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    for (size_t i = 0; i <= n; ++i) {
        for (size_t j = 0; j <= W; ++j) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else {
                int pick = 0;
                if (weight[i - 1] <= j)
                    pick = profit[i - 1] + dp[i - 1][j - weight[i - 1]];
                
                int notPick = dp[i - 1][j];

                dp[i][j] = max(pick, notPick);
            }
        }
    }
    return dp[n][W];
}


// Bottom-Up DP (Space-Optimized), O(n x W) Time and O(W) Space
int knapsackBottomUpSOp(size_t W, size_t n, vector<int> &profit, vector<size_t> &weight) {
    vector<int> dp(W + 1, 0);

    for (size_t i = 1; i <= n; ++i)
        for (size_t j = W; j >= weight[i - 1]; --j)
            dp[j] = max(dp[j], dp[j - weight[i - 1]] + profit[i - 1]);

    return dp[W];
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; cin >> t;
    while (t--) {
        size_t W = 0, n = 0; cin >> W >> n;
        vector<int> profit(n);
        vector<size_t> weight(n);
        for (auto &e : profit) cin >> e;
        for (auto &e : weight) cin >> e;

        cout << knapsackBottomUpSOp(W, n, profit, weight) << '\n';
    }

    return 0;
}
