#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int> (w+1, -1));

    for(int val = 0 ; val <= w ; val++)
    {
        if (val >= weight[0])
            dp[0][val] = (val / weight[0]) * profit[0];
        else
            dp[0][val] = 0;
    }
    
    for(int index = 1 ; index < n ; index++)
    {
        for(int val = 0 ; val <= w ; val++)
        {
            int nTake = dp[index-1][val];
            int take = INT_MIN;
            if(weight[index] <= val) 
                take = profit[index] + dp[index][val-weight[index]];

            dp[index][val] = max(nTake, take);
        }
    }

    return dp[n-1][w];
}
