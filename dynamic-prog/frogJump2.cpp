#include <bits/stdc++.h>
using namespace std;


int func(int index, vector<int> &dp, vector<int> &heights, int k)
{
    if(index == 0) return 0;

    if(dp[index] != -1) return dp[index];

    int minVal = INT_MAX;

    for(int i = 1 ; i <= k ; i++)
    {
        if((index - i) >= 0)
        {
            //calculating the engery for k distance jump.
            int jump = func(index - i, dp, heights, k) + abs(heights[index] - heights[index - i]);
            minVal = min(jump, minVal);
        }
    }

    return dp[index] = minVal;
}

int frogJump(int n, vector<int> &heights, int k)
{
    vector<int> dp(n+1, -1);
    return func(n-1, dp, heights, k);
}

int main()
{
    vector<int> arr = {15, 4, 1, 14, 15};
    int n = arr.size();
    int k = 3;

    int ans = frogJump(n, arr, k);

    cout<<"Min Energy : "<<ans<<endl;

    return 0;
}