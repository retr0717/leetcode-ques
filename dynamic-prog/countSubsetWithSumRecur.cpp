#include <bits/stdc++.h>
using namespace std;

int Count(vector<int> &arr, int tar, int index)
{
	if(tar == 0) return 1;
	if(index == 0) return arr[index] == tar;

	int notTake = Count(arr, tar, index-1);
	int take = 0;
	if( tar >= arr[index])
		take = Count(arr, tar - arr[index], index-1);
	
	return take+notTake;
}

int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	return Count(arr, k, n-1);
}

