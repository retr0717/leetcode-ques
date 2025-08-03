#include <bits/stdc++.h>
using namespace std;

int cutRod(vector<int> &price, int n)
{
	int m = price.size();
	vector<int> prev(n+1, 0), curr(n+1, 0);

	for(int i = 0 ; i <= n ; i++)
		prev[i] = i * price[0];
	
	for(int index = 1; index < m; index++)
	{
		int rodLength = index +1;
		for(int rodLen = 0 ; rodLen <= n ; rodLen++)
		{
			int nTake = prev[rodLen];
			int take = INT_MIN;
			if(rodLength <= rodLen)
				take = price[index] + curr[rodLen - rodLength];

			curr[rodLen] = max(take, nTake);
		}
		prev = curr;
	}

	return prev[n];
}
