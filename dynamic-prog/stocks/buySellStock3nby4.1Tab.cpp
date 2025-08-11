#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));
        int profit = 0;
        for(int index = n-1 ; index >= 0 ; index--)
        {
            for(int tNo = 2*k-1; tNo >= 0 ; tNo--)
            {
                if(tNo%2 == 0)//buy
                {
                    profit = max(-prices[index] + dp[index+1][tNo+1], dp[index+1][tNo]);
                }
                else
                {
                    //sell
                    profit = max(prices[index] + dp[index+1][tNo+1], dp[index+1][tNo]);
                }

                dp[index][tNo] = profit;
            }
        }
        return dp[0][0];
    }
};
