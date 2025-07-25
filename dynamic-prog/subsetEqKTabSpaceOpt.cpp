#include <bits/stdc++.h> 
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1, 0), curr(k+1, 0);

    prev[0] = curr[0] = true;

    prev[arr[0]] = true;

    for(int i = 1 ; i < n ; i++)
    {
        for(int j = 1 ; j <= k ; j++)
        {
            bool notTake = prev[j];

            bool take = false;
            if (j >= arr[i])
                take = prev[j - arr[i]];
            
            curr[j] = take || notTake;
        }

        prev = curr;
    }

    return prev[k];
}
