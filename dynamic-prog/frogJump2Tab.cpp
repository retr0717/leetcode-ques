#include <bits/stdc++.h> 
using namespace std;

int frogJump(int n, vector<int> &heights, int k)
{
    vector<int> dp(n, -1);

    dp[0] = 0;

    for(int i = 1; i < n; i++)
    {
        int minVal = INT_MAX;

        for(int j = 1 ; j <= k ; j++)
        {
            if((i - j) < 0) continue; // Skip if the jump goes out of bounds
            int jump = dp[i-j] + abs(heights[i] - heights[i-j]);
            minVal = min(jump, minVal);
        }

        dp[i] = minVal;
    }

    return dp[n-1];
}

int main()
{
    vector<int> arr = {15, 4, 1, 14, 15};
    int n = arr.size();
    int k = 3;

    int ans = frogJump(n, arr, k);

    cout << "Min Energy : " << ans << endl;

    return 0;
}