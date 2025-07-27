#include <bits/stdc++.h>
using namespace std;

int func(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
        if(index == 0)
        {
                if(target == 0 && arr[0] == 0)
                        return 2;
                if(target == 0)
                        return 1;
        }

	if(dp[index][target] != -1) return dp[index][target];

        int notTake = Count(arr, tar, index-1, dp);
        int take = 0;
        if( tar >= arr[index])
                take = Count(arr, tar - arr[index], index-1, dp);

        return dp[index][target] = take+notTake;
}

int findWays(vector<int> &arr, int k)
{
	vector<vector<int> dp(n, vector<int> (k+1, -1));
        int n = arr.size();
        return func(n-1, k, arr, dp);
}
