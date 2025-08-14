#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(int index, bool buy, vector<int>& prices, int n, int fee, vector<vector<int>> &dp)
    {
        if(index == n)
            return 0;

        int profit = 0;
        if(buy)
        {
            profit = max(-prices[index] + f(index+1, 0, prices, n, fee, dp), f(index+1, 1, prices, n, fee, dp)); 
        }
        else
        {
            profit = max(prices[index] + f(index+1, 1, prices, n, fee, dp) - fee, f(index+1, 0, prices, n, fee, dp));
        }

        return profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, -1));

        return f(0, 1, prices, n, fee, dp);
    }
};
