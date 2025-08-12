#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(int index, int buy, vector<int>& prices, int n, vector<vector<int>>& dp)
    {
        if(index >= n) return 0;

        if(dp[index][buy] != -1) return dp[index][buy];

        if(buy)
        {
            return dp[index][buy] = max(-prices[index] + f(index+1, 0, prices, n, dp), f(index+1, 1, prices, n, dp));
        }
        
        return dp[index][buy] = max(prices[index] + f(index+2, 1, prices, n, dp), f(index+1, 0, prices, n, dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        
        return f(0, 1, prices, n, dp);
    }
};
