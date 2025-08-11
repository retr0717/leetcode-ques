#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(int index, int transaction, vector<int>& prices, int n)
    {
        if(transaction == 0 || index == n)
            return 0;

        int profit = 0;
        if(transaction%2 == 0)//buy
        {
            profit = max(-prices[index] + f(index+1, transaction+1, prices, n), f(index+1, transaction, prices, n)); 
        }
        else//sell
        {
            profit = max(prices[index] + f(index+1, transaction+1, prices, n), f(index+1, transaction, prices, n));
        }

        return profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return f(0, 0, prices, n); 
    }
};

