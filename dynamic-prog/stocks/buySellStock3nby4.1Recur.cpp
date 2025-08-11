#include <bits/stdc++.h>
using namespace std;

class Solution {
int f(int index, int tNo , vector<int>& prices, int n, int k)
{
    if(index == n || tNo == 2*k) return 0;

    if(tNo%2 == 0)//buy
    {
        return max(-prices[index] + f(index+1, tNo+1, prices, n, k), f(index+1, tNo, prices, n, k));
    }

    //sell
    return max(prices[index] + f(index+1, tNo+1, prices, n, k), f(index+1, tNo, prices, n , k));
}
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        return f(0, 0, prices, n, k);
    }
};
