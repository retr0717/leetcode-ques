#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> after(2, 0), curr(2, 0);

        for(int index = n-1; index >= 0 ; index--)
        {
            for(int buy = 0; buy < 2; buy++)
            {
                int profit = 0;
                if(buy)
                {
                    profit = max(-prices[index] + after[0], after[1]); 
                }
                else
                {
                    profit = max(prices[index] + after[1] - fee, after[0]);
                }

                curr[buy] = profit;
            }

            after = curr;
        }

        return curr[1];
    }
};
