#include <bits/stdc++.h>
using namespace std;

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

