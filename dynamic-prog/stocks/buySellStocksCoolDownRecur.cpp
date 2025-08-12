#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(int index, int buy, vector<int>& prices, int n)
    {
        if(index >= n) return 0;

        if(buy)
        {
            return max(-prices[index] + f(index+1, 0, prices, n), f(index+1, 1, prices, n));
        }
        
        return max(prices[index] + f(index+2, 1, prices, n), f(index+1, 0, prices, n));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        return f(0, 1, prices, n);
    }
};
