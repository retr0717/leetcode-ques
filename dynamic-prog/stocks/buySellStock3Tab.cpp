#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));

        for(int i = n-1 ; i >= 0 ; i--)
        {
            for(int j = 0 ; j < 2; j++)
            {
                for(int cap = 1 ; cap < 3; cap++)
                {
                    int profit = 0;
                    if(j)
                        profit = max(-prices[i] + dp[i+1][0][cap], dp[i+1][1][cap]);
                    else
                        profit = max(prices[i] + dp[i+1][1][cap-1], dp[i+1][0][cap]);

                    dp[i][j][cap] = profit;
                }
            }

        }
        
        return dp[0][1][2];
    }
};
