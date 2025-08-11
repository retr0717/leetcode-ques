#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> after(2*k+1, 0), curr(2*k+1, 0);
        int profit = 0;

        for(int index = n-1 ; index >= 0 ; index--)
        {
            for(int tNo = 2*k-1; tNo >= 0 ; tNo--)
            {
                if(tNo%2 == 0)//buy
                {
                    profit = max(-prices[index] + after[tNo+1], after[tNo]);
                }
                else
                {
                    //sell
                    profit = max(prices[index] + after[tNo+1], after[tNo]);
                }

                curr[tNo] = profit;
            }
            after = curr;
        }
        return after[0];
    }
};
