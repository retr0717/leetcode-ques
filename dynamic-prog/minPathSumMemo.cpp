#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long MinPath(int m , int n, vector<vector<int>> &grid, vector<vector<long>> &dp)
    {
        if( m == 0 && n == 0) return grid[0][0];
        
        if(m < 0 || n < 0) return INT_MAX;

        if(dp[m][n] != -1) return dp[m][n];

        //compute all the path and find min.
        long up = grid[m][n] + MinPath(m-1, n, grid, dp);
        long left = grid[m][n] + MinPath(m, n-1, grid, dp);

        return dp[m][n] = min(up, left);
    }
public:
    long minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long>> dp(m, vector<long> (n, -1));

        return MinPath(m-1, n-1, grid, dp);
    }
};
