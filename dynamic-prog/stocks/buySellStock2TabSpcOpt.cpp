#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2, 0), curr(2, 0);

        ahead[0] = ahead[1] = 0;

        for(int i = n-1 ; i >= 0 ; i--)
        {
            for(int j = 0 ; j < 2; j++)
            {
                int profit = 0;
                if(j)
                    profit = max(-prices[i] + ahead[0], ahead[1]);
                else
                    profit = max(prices[i] + ahead[1], ahead[0]);

                curr[j] = profit;
            }

            ahead = curr;
        }
        
        return ahead[1];
    }
};
