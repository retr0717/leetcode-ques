#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int findWays(int ind, int tar, vector<int>& coins, vector<vector<int>>& dp)
    {
        if(ind == 0)    return (tar%coins[0] == 0);

        if(dp[ind][tar] != -1) return dp[ind][tar];

        //notTake.
        int nTake = findWays(ind-1, tar, coins, dp);
        int take = 0;
        //take if less than the target.
        if(coins[ind] <= tar) take = findWays(ind, tar-coins[ind], coins, dp);

        return dp[ind][tar] = (nTake+take);
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return findWays(n-1, amount, coins, dp);
    }
};
