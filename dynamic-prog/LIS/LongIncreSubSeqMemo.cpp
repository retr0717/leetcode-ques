#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(int curr, int prev, vector<int>& nums, int n, vector<vector<int>>& dp)
    {
        if(curr == n) return 0;

        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
        //not take.
        int len = 0 + f(curr+1, prev, nums, n, dp);
        if(prev == -1 || nums[curr] > nums[prev])
            len = max(len, 1 + f(curr+1, curr, nums, n, dp));
        
        return dp[curr][prev+1] = len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

        return f(0, -1, nums, n, dp);
    }
};
