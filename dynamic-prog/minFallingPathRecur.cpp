#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int MinPath(int i, int j, vector<vector<int>> matrix, int n)
    {
        if( j < 0 || j >= n) return 1e9;

        if(i == n-1) return matrix[i][j];

        int down = matrix[i][j] + MinPath(i+1, j, matrix, n);
        int rDiag = matrix[i][j] + MinPath(i+1, j+1, matrix, n);
        int lDiag = matrix[i][j] + MinPath(i+1, j-1, matrix, n);

        return min(down, min(rDiag, lDiag));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int minVal = 1e9;

        for(int i = 0 ; i < n; i++)
        {
            minVal = min(minVal, MinPath(0, i, matrix, n));
        }

        return minVal;
    }
};
