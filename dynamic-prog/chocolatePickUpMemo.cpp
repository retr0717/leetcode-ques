#include <bits/stdc++.h> 

int MaxChoco(int i, int j1, int j2, vector<vector<int>> &grid, int n, int m, vector<vector<vector<int>>> &dp)
{
    if(i < 0 || j1 < 0 || j2 < 0 || j1 >= m || j2 >= m) return -1e8;

    if(i == n-1)
    {
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }

    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

    //try all 9 combo moves.
    // -1 to +1.
    int maxVal = -1e8;
    for(int di = -1; di <= 1; di++)
    {
        for(int dj = -1; dj <= 1; dj++)
        {
            if(j1 == j2) maxVal = max(maxVal, grid[i][j1] + MaxChoco(i+1, j1+di, j2+dj, grid, n, m, dp));
            else maxVal = max(maxVal, grid[i][j1] + grid[i][j2] + MaxChoco(i+1, j1+di, j2+dj, grid, n, m, dp));
        }
    }

    return dp[i][j1][j2] = maxVal;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    int n = grid.size(); //row no.
    int m = grid[0].size(); //col no.

    vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m , -1)));

    return MaxChoco(0, 0, m-1, grid, n, m, dp);
}
