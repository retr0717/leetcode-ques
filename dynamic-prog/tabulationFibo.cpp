#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int dp[n+1];
	dp[0] = 0, dp[1] = 1;
	for(int i = 2 ; i <= n ; i++)
	{
		dp[i] = dp[i-1] + dp[i-2];
	}

	withNoExtraSpace(dp, n);
	return 0;
}

void withNoExtraSpace(int dp[], n)
{
	int prev = 1;
	int prev2 = 0;

	for(int i = 2 ; i <= n ; i++)
	{
		int curr = prev + prev2;
		prev2 = prev;
		prev = curr;
	}
}
