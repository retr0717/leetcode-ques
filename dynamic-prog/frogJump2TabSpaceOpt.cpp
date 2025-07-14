#include <bits/stdc++.h> 
using namespace std;

int frogJump(int n, vector<int> &heights, int k)
{
    vector<int> dp(k, INT_MAX); // Using k size to optimize space
    dp[0] = 0; // Base case: no energy needed to stay on the first stone

    for(int i = 1; i < n; i++)
    {
        int curr = INT_MAX;

        for(int j = 1 ; j <= k ; j++)
        {
            if((i - j) < 0)  continue;
            curr  = min(curr, dp[(i-j)%k] + abs(heights[i] - heights[i-j]));
        }
        // Store the current minimum energy in the dp array
        dp[i % k] = curr;
    }

    return dp[(n-1) % k];
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