#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> curr(n+1, 0), next(n+1, 0);

        int len = 0;

        for(int ind = n-1 ; ind >= 0 ; ind--)
        {
            for(int prevInd = ind - 1 ; prevInd >= -1 ; prevInd--)
            {
                len = 0 + next[prevInd + 1];
                if(prevInd == -1 || nums[ind] > nums[prevInd])
                    len = max(len, 1+ next[ind + 1]);
                
                curr[prevInd+1] = len;
            }

            next = curr;
        }

        return next[0];
    }
};
