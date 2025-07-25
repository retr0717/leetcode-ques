#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool EqualPartition(vector<int> &nums, int index, int target)
    {
        if(target == 0) return true;
        if(index == 0) return nums[0] == target;
        
        //calculate the sum
        bool notTake = EqualPartition(nums, index-1, target);
        bool take = false;
        if(target >= nums[index])
            take = EqualPartition(nums, index-1, target - nums[index]);
        
        return take || notTake;
    }

public:
    bool canPartition(vector<int>& nums) {

        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total % 2 != 0) return false;

        int target = total / 2;
        int n = nums.size();

        return EqualPartition(nums, n-1, target);
    }
};
