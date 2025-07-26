#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total % 2 != 0) return false;

        int target = total / 2;
        int n = nums.size();
        vector<int> prev(target+1, false), curr(target+1, false);

        for(int i = 0 ; i < n ; i++) prev[0] = true;

        if(nums[0] <= target) prev[nums[0]] = true;

        for(int i = 1 ; i < n ; i++)
        {
            for(int j = 1 ; j <= target ; j++)
            {
                bool notTake = prev[j];
                bool take = false;
                if(j >= nums[i])
                    take = prev[j-nums[i]];
                
                curr[j] = take || notTake;
            }

            prev = curr;
        }

        return prev[target];
    }
};
