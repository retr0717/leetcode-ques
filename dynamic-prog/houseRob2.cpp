#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int MaxRob(vector<int> &nums)
    {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;

        for(int i = 1; i < n ; i++)
        {
            int pick = nums[i];
            if(i > 0) pick += prev2;

            int notPick = prev;

            prev2 = prev;
            prev = max(pick, notPick);
        }

        return prev;
    }
public:
    int rob(vector<int>& nums) {
        vector<int> temp1, temp2;
        int n = nums.size();

        //handling the single item array.
        if(n == 1) return nums[0];

        for(int i = 0 ; i < n ; i++)
        {
            //array without the first element.
            if(i != 0) temp1.push_back(nums[i]);

            //array without the last element.
            if(i != n-1) temp2.push_back(nums[i]);
        }

        //calculating the max element from the both segments.
        return max(MaxRob(temp1), MaxRob(temp2));
    }
};
