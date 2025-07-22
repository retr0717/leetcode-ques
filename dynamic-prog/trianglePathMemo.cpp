#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int MinPath(int i , int j, vector<vector<int>> &arr, int n, vector<vector<int>> &dp)
    {
        if(i == n-1) return arr[n-1][j];

        if(dp[i][j] != -1) return dp[i][j];

        int down = arr[i][j] + MinPath(i+1, j, arr, n, dp);
        int diag = arr[i][j] + MinPath(i+1, j+1, arr, n, dp);

        return dp[i][j] = min(down, diag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        vector<vector<int>> dp;
        for (int i = 0; i < n; ++i)
            dp.push_back(vector<int>(triangle[i].size(), -1));

        return MinPath(0, 0, triangle, n, dp);
    }
};
