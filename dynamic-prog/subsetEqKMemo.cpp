#include <bits/stdc++.h> 
using namespace std;

bool SubSum(vector<int> &arr, int target, int index, vector<vector<int>> &dp)
{
    if(target == 0) return true;
    if (index == 0) return arr[0] == target;

    if(dp[index][target] != -1) return dp[index][target];

    bool notTake = SubSum(arr, target, index - 1, dp);
    bool take = false;
    if (target >= arr[index])
        take = SubSum(arr, target - arr[index], index - 1, dp);

    return dp[index][target] = take || notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int> (k+1, -1));
    return SubSum(arr, k, n-1, dp);
}
