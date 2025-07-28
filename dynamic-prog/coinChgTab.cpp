#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        const int INF = 1e8;
        vector<vector<int>> dp(n, vector<int>(amount + 1, INF));

        //only using the first coin
        for(int j = 0; j <= amount; j++) {
            if(j % coins[0] == 0)
                dp[0][j] = j / coins[0];
        }

        // Build the table
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= amount; j++) {
                int notTake = dp[i - 1][j];
                int take = INF;
                if(j >= coins[i])
                    take = 1 + dp[i][j - coins[i]];
                dp[i][j] = min(take, notTake);
            }
        }

        return (dp[n - 1][amount] >= INF) ? -1 : dp[n - 1][amount];
    }
};
