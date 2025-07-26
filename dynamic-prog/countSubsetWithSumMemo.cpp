#include <bits/stdc++.h>
using namespace std;

int Count(vector<int> &arr, int tar, int index, vector<vector<int>> &dp)
{
	if(tar == 0) return 1;
	if(index == 0) return arr[index] == tar;

	if(dp[index][tar] != -1) return dp[index][tar];

	int notTake = Count(arr, tar, index-1, dp);
	int take = 0;
	if( tar >= arr[index])
		take = Count(arr, tar - arr[index], index-1, dp);
	
	return dp[index][tar] = take+notTake;
}

int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int> (k+1, -1));
	return Count(arr, k, n-1, dp);
}

