#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int robFunc(vector<int> &nums, int index)
    {
        if(index == 0) return nums[index];
        if(index < 0) return 0;

        //pick
        int pick = nums[index] + robFunc(nums, index-2);

        //not-pick
        int notPick = 0 + robFunc(nums, index-1);

        return max(pick, notPick);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return robFunc(nums, n-1);
    }
};

int main()
{
	vector<int> arr = {1, 2, 3, 1};
	Solution sol;
	int ans = sol.rob(arr);

	cout<<"ans : "<<ans<<endl;

	return 0;
}
