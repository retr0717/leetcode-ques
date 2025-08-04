#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long maxProfit(vector<int>& prices) {

        if(prices.size() == 1) return 0;

        int mini = prices[0];
        int maxProfit = 0;
        int n = prices.size();
        for(int i = 0 ; i < n ; i++)
        {
            int cost = prices[i] - mini;
            maxProfit = max(maxProfit, cost);
            mini = min(mini, prices[i]);
        }

        return maxProfit;
    }
};
