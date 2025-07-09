#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int ways(int index, vector<int> &dp)
    {
        if(index == 0 || index == 1) return 1;

        if(dp[index] != -1) return dp[index];

        dp[index] = ways(index-1, dp) + ways(index-2, dp);

        return dp[index];
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return ways(n, dp);
    }
};
