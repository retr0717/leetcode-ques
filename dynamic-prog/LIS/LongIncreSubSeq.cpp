#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(int curr, int prev, vector<int>& nums, int n)
    {
        if(curr == n) return 0;

        //not take.
        int len = 0 + f(curr+1, prev, nums, n);
        if(prev == -1 || nums[curr] > nums[prev])
            len = max(len, 1 + f(curr+1, curr, nums, n));
        
        return len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        return f(0, -1, nums, n);
    }
};
