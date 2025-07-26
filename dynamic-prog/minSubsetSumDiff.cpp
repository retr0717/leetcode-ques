#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int>& nums, int n)
{
		int totSum = 0;

        if (n == 0) return 0;

        for (int i = 0; i < n; i++) totSum += nums[i];

        vector<vector<bool>> dp(n, vector<bool>(totSum + 1, 0));

        for (int i = 0; i < n; i++) dp[i][0] = true;

        if (nums[0] >= 0 && nums[0] <= totSum)
            dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= totSum; j++) {
                bool notTake = dp[i - 1][j];
                bool take = false;
                if (j >= nums[i])
                    take = dp[i - 1][j - nums[i]];
                dp[i][j] = take || notTake;
            }
        }

        int minVal = 1e9;
        for (int s1 = 0; s1 <= totSum / 2; s1++) {
            if (dp[n - 1][s1])
                minVal = min(minVal, abs((totSum - s1) - s1));
        }

        return minVal;
}

