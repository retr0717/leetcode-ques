#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long>> dp(m, vector<long> (n, -1));

        for(long i = 0 ; i < m ; i++)
        {
            for(long j = 0 ; j < n ; j++)
            {
                if(i == 0 && j == 0) dp[i][j] = grid[0][0];
                else{
                        //compute all the path and find min.
                        long up = grid[i][j];
                        if(i > 0) up += dp[i-1][j];
                        else up += 1e9;

                        long left = grid[i][j];
                        if(j > 0) left += dp[i][j-1];
                        else left += 1e9;

                        dp[i][j] = min(up,left);
                }
            }
        }

        return dp[m-1][n-1];
    }
};
