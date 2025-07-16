#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int rob(vector<int> &nums, int index, vector<int> &dp)
    {
        if(index == 0) return nums[index];
        if(index < 0) return 0;

        //memoization.
        if(dp[index] != -1) return dp[index];

        //pick
        int pick = nums[index] + rob(nums, index-2, dp);

        //not-pick
        int notPick = 0 + rob(nums, index-1, dp);

        return dp[index] = max(pick, notPick);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        return rob(nums, n-1, dp);
    }
};
