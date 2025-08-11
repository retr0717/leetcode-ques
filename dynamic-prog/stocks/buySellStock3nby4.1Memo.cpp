#include <bits/stdc++.h>
using namespace std;

class Solution {
int f(int index, int tNo , vector<int>& prices, int n, int k, vector<vector<int>>& dp)
{
    if(index == n || tNo == 2*k) return 0;

    if(dp[index][tNo] != -1) return dp[index][tNo];

    if(tNo%2 == 0)//buy
    {
        return dp[index][tNo] = max(-prices[index] + f(index+1, tNo+1, prices, n, k, dp), f(index+1, tNo, prices, n, k, dp));
    }

    //sell
    return dp[index][tNo] = max(prices[index] + f(index+1, tNo+1, prices, n, k, dp), f(index+1, tNo, prices, n , k, dp));
}
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2*k+1, -1));
        return f(0, 0, prices, n, k, dp);
    }
};
