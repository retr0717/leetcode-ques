#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        //keeping track of the no of subsequences.
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        int maxVal = 0;

        for(int i = 0 ; i < n ; i++)
        {
            //prev index loop
            for(int j = 0 ; j < i ; j++)
            {
                //take logic.
                //strictly increasing.
                if(nums[i] > nums[j] && 1+dp[j] > dp[i])
                {
                    dp[i] = 1 + dp[j];
                    count[i] = count[j];
                }
                else if(nums[i] > nums[j] && 1+dp[j] == dp[i])
                    count[i] += count[j];
            }

            maxVal = max(maxVal, dp[i]);
        }

        int nos = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(dp[i] == maxVal) nos += count[i];
        }

        return nos;
    }
};
