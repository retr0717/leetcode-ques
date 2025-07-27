#include <bits/stdc++.h>
using namespace std;

int mod =(int)1e9+7;

int findWays(vector<int> &arr, int k)
{
        vector<int> prev(k+1, 0);
        int n = arr.size();

        if(arr[0] == 0) prev[0] = 2;
        else prev[0] = 1;

        if(arr[0] != 0 && arr[0] <= k) prev[arr[0]] = 1;

        for(int i = 1 ; i < n ; i++)
        {
		vector<int> temp(k+1, 0);
                for(int j = 0 ; j <= k ; j++)
                {
                        int notTake = prev[j];

                        int take = 0;
                        if (j >= arr[i])
                                take = prev[j - arr[i]];
            
                        temp[j] = take + notTake % mod;
                }
		prev = temp;
        }

        return prev[k];
}
