#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        int len = 0;

        for(int ind = n-1 ; ind >= 0 ; ind--)
        {
            for(int prevInd = ind - 1 ; prevInd >= -1 ; prevInd--)
            {
                len = 0 + dp[ind+1][prevInd + 1];
                if(prevInd == -1 || nums[ind] > nums[prevInd])
                    len = max(len, 1+dp[ind+1][ind + 1]);
                
                dp[ind][prevInd+1] = len;
            }
        }

        return dp[0][0];
    }
};
