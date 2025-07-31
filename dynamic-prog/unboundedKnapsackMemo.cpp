#include <bits/stdc++.h>
using namespace std;

int maxProfit(int index, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>>& dp)
{
    if(index == 0) return ((w/weight[0])*profit[index]);

    if(dp[index][w] != -1) return dp[index][w];

    int nTake = maxProfit(index-1, w, profit, weight, dp);
    int take = INT_MIN;
    if(weight[index] <= w) 
        take = profit[index] + maxProfit(index, w-weight[index], profit, weight, dp);

    return dp[index][w] = max(nTake, take);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int> (w+1, -1));
    return maxProfit(n-1, w, profit, weight, dp);
}
