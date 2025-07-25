#include <bits/stdc+.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total % 2 != 0) return false;

        int target = total / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (target+1, false));

        for(int i = 0 ; i < n ; i++) dp[i][0] = true;

        if(nums[0] <= target) dp[0][nums[0]] = true;

        for(int i = 1 ; i < n ; i++)
        {
            for(int j = 1 ; j <= target ; j++)
            {
                bool notTake = dp[i-1][j];
                bool take = false;
                if(j >= nums[i])
                    take = dp[i-1][j-nums[i]];
                
                dp[i][j] = take || notTake;
            }
        }

        return dp[n-1][target];
    }
};
