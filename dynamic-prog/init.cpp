#include <bits/stdc++.h>
using namespace std;

int fn(int n, vector<int> &dp)
{
	if(n <= 1) return ;

	if(dp[n] != -1) return dp[n];

	return dp[n] = fn(n-1, dp) + fn(n-2, dp);
}

int main()
{
	int n = 5;
	cin>>n;
	vector<int> dp(n, -1);
	cout<<fn(n, dp);0
	return 0;
}
