#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int minVal = 1e9;
        vector<vector<int>> dp(n, vector<int> (matrix[0].size(), -1));

        for(int i = 0 ; i < n ; i++)
            dp[0][i] = matrix[0][i];
        
        for(int i = 1; i < n ; i++)
        {
            for(int j = 0; j < n ; j++)
            {
                int down = 1e9, rDiag = 1e9, lDiag = 1e9;
                down = matrix[i][j] + dp[i-1][j];
                if(j+1 < n) rDiag = matrix[i][j] + dp[i-1][j+1];
                if(j-1 >= 0) lDiag = matrix[i][j] + dp[i-1][j-1];

                dp[i][j] = min(down, min(rDiag, lDiag));
            }
        }

        for(int i = 0 ; i < n ; i++)
            minVal = min(minVal, dp[n-1][i]);

        return minVal;
    }
};
