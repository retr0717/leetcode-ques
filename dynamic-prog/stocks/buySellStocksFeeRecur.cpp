#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(int index, bool buy, vector<int>& prices, int n, int fee)
    {
        if(index == n)
            return 0;

        int profit = 0;
        if(buy)
        {
            profit = max(-prices[index] + f(index+1, 0, prices, n, fee), f(index+1, 1, prices, n, fee)); 
        }
        else
        {
            profit = max(prices[index] + f(index+1, 1, prices, n, fee) - fee, f(index+1, 0, prices, n, fee));
        }

        return profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        return f(0, 1, prices, n, fee);
    }
};
