#include <bits/stdc++.h>
using namespace std;

int func(int index, int target, vector<int> &arr)
{
	if(index == 0)
	{
		if(target == 0 && arr[0] == 0)
			return 2;
		if(target == 0)
			return 1;
	}

	int notTake = Count(arr, tar, index-1);
        int take = 0;
        if( tar >= arr[index])
                take = Count(arr, tar - arr[index], index-1);

        return take+notTake;
}

int findWays(vector<int> &arr, int k)
{
	int n = arr.size();
	return func(n-1, k, arr);
}
