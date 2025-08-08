#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(int index, bool buy, int cap, vector<int>& prices, int n)
    {
        if(cap == 0 || index == n)
            return 0;

        int profit = 0;
        if(buy)
        {
            profit = max(-prices[index] + f(index+1, 0, cap, prices, n), f(index+1, 1, cap, prices, n)); 
        }
        else
        {
            profit = max(prices[index] + f(index+1, 1, cap-1, prices, n), f(index+1, 0, cap, prices, n));
        }

        return profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return f(0, 1, 2, prices, n); 
    }
};
