#include <bits/stdc++.h>
using namespace std;

int partitions(int i , int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if(i == j ) return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int mini = 1e9;

    //get all partitions.
    for(int k = i ; k < j ; k++)
    {
        int steps = partitions(i , k , arr, dp) + partitions(k + 1 , j , arr, dp) + arr[i - 1] * arr[k] * arr[j];
        //minimize the steps.

        if(steps < mini)
            mini = steps;
    }
    return dp[i][j] = mini;
} 

int main()
{
    vector<int> arr = {10, 20, 30, 40, 30};
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << "Minimum number of multiplications is " << partitions(1, n - 1, arr, dp) << endl;

    return 0;
}