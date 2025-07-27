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

int mod =(int)1e9+7;

int findWays(vector<int> &arr, int k)
{
        vector<vector<int> dp(n, vector<int> (k+1, -1));
        int n = arr.size();

	if(arr[0] == 0) dp[0][0] = 2;
	else dp[0][0] = 1;

	if(arr[0] != 0 && arr[0] <= k) dp[0][arr[0]] = 1;

	for(int i = 1 ; i < n ; i++)
	{
		for(int j = 0 ; j <= k ; j++)
		{
			int notTake = dp[i-1][j];

            		int take = 0;
            		if (j >= arr[i])
                		take = dp[i-1][j - arr[i]];
            
            		dp[i][j] = take + notTake % mod;
		}
	}

        return dp[n-1][k];
}

