#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int> (3, 0)), curr(2, vector<int> (3, 0));

        for(int i = n-1 ; i >= 0 ; i--)
        {
            for(int j = 0 ; j < 2; j++)
            {
                for(int cap = 1 ; cap < 3; cap++)
                {
                    int profit = 0;
                    if(j)
                        profit = max(-prices[i] + after[0][cap], after[1][cap]);
                    else
                        profit = max(prices[i] + after[1][cap-1], after[0][cap]);

                    curr[j][cap] = profit;
                }
            }

            after = curr;
        }
        
        return curr[1][2];
    }
};
