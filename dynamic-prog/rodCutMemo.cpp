#include <bits/stdc++.h>
using namespace std;

int maxCost(int index,int length, vector<int>& price, vector<vector<int>>& dp)
{
	if(index == 0){
		return length * price[0];
	}

	if(dp[index][length] != -1) return dp[index][length];

	int nTake = maxCost(index-1, length, price, dp);
	int rodLength = index +1;
	int take = INT_MIN;
	if(rodLength <= length)
		take = price[index] + maxCost(index, length-rodLength, price, dp);

	return dp[index][length] = max(take, nTake);
}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(price.size(), vector<int> (n+1, -1));
	return maxCost(price.size()-1, n, price, dp);
}
