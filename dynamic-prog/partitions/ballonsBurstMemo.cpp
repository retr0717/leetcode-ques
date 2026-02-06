#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(int i, int j, vector<int>& nums, vector<vector<int>>& dp)
    {
        if(i > j )
            return 0;
        
        int maxi = INT_MIN;

        for(int k = i; k <= j; k++)
        {
            if(dp[i][j] != -1) return dp[i][j];
            int coins = nums[i-1] * nums[k] * nums[j+1] + f(i, k-1, nums, dp) + f(k+1, j, nums, dp);

            maxi = max(maxi, coins);
        }

        return dp[i][j] = maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return f(1, n, nums, dp);
    }
};

int main()
{
    vector<int> nums = {3, 1, 5, 8};

    Solution obj;
    cout << "Maximum coins that can be obtained is " << obj.maxCoins(nums) << endl;

    return 0;
}