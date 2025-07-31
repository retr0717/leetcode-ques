#include <bits/stdc++.h>
using namespace std;

int maxProfit(int index, int w, vector<int> &profit, vector<int> &weight)
{
    if(index == 0) return ((w/weight[0])*profit[index]);

    int nTake = maxProfit(index-1, w, profit, weight);
    int take = INT_MIN;
    if(weight[index] <= w) 
        take = profit[index] + maxProfit(index, w-weight[index], profit, weight);

    return max(nTake, take);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    return maxProfit(n-1, w, profit, weight);
}
