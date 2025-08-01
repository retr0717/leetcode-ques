#include <bits/stdc++.h>
using namespace std;

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(price.size(), vector<int> (n+1, -1));

	for(int i = 0 ; i <= n ; i++)
		dp[0][i] = i * price[0];
	
	for(int index = 1; index < price.size(); index++)
	{
		int rodLength = index +1;
		for(int rodLen = 0 ; rodLen <= n ; rodLen++)
		{
			int nTake = dp[index-1][rodLen];
			int take = INT_MIN;
			if(rodLength <= rodLen)
				take = price[index] + dp[index][rodLen - rodLength];

			dp[index][rodLen] = max(take, nTake);
		}
	}

	return dp[price.size()-1][n];
}
