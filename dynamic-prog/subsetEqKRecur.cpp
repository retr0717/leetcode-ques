#include <bits/stdc++.h> 
using namespace std;

bool SubSum(vector<int> &arr, int target, int index)
{
    if(target == 0) return true;
    if (index == 0) return arr[0] == target;

    bool notTake = SubSum(arr, target, index - 1);
    bool take = false;
    if (target >= arr[index])
        take = SubSum(arr, target - arr[index], index - 1);

    return take || notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    return SubSum(arr, k, n-1);
}
