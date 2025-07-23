#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int MinPath(int i, int j, vector<vector<int>> matrix, int n, vector<vector<int>> &dp)
    {
        if( j < 0 || j >= n) return 1e9;

        if(i == n-1) return matrix[i][j];

        if( dp[i][j] != -1 ) return dp[i][j];

        int down = matrix[i][j] + MinPath(i+1, j, matrix, n, dp);
        int rDiag = matrix[i][j] + MinPath(i+1, j+1, matrix, n, dp);
        int lDiag = matrix[i][j] + MinPath(i+1, j-1, matrix, n, dp);

        return dp[i][j] = min(down, min(rDiag, lDiag));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int minVal = 1e9;
        vector<vector<int>> dp(n, vector<int> (matrix[0].size(), -1));

        for(int i = 0 ; i < n; i++)
        {
            minVal = min(minVal, MinPath(0, i, matrix, n, dp));
        }

        return minVal;
    }
};
