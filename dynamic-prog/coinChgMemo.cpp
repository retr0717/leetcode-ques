#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int MinCoins(int index, int tar, vector<int> &coins, vector<vector<int>> &dp)
    {
        if(index == 0)
        {
            if( (tar%coins[index]) == 0) return (tar/coins[0]);
            else return 1e8;
        }

        if(dp[index][tar] != -1) return dp[index][tar];

        int nTake = MinCoins(index-1, tar, coins, dp);
        int take = 1e8;
        if(tar >= coins[index])
            take = 1 + MinCoins(index, tar-coins[index], coins, dp);
        
        return dp[index][tar] = min(take, nTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int> (amount+1, -1));

        int ans = MinCoins(n-1, amount, coins, dp);
        return (ans >= 1e8) ? -1 : ans;
    }
};
