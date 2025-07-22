#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int Path(vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp)
    {
        //path exists.
        if( m == 0 && n == 0) return 1;
        
        //boundary check.
        if( m < 0 || n < 0) return 0;

        if(grid[m][n] == 1) return 0;

        //precomputed value.
        if(dp[m][n] != -1) return dp[m][n];

        //move up and left.
        int up = Path(grid, m-1, n, dp);
        int left = Path(grid, m, n-1, dp);

        return dp[m][n] = (up+left);
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1) return 0;

        vector<vector<int>> dp(m, vector<int> (n, -1));

        return Path(obstacleGrid, m-1, n-1, dp);
    }
};
