#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int minVal = 1e9;
        vector<int> prev(n, 0);

        for(int i = 0 ; i < n ; i++)
            prev[i] = matrix[0][i];
        
        for(int i = 1; i < n ; i++)
        {
            vector<int> temp(n, 0);
            for(int j = 0; j < n ; j++)
            {
                int down = 1e9, rDiag = 1e9, lDiag = 1e9;
                down = matrix[i][j] + prev[j];
                if(j+1 < n) rDiag = matrix[i][j] + prev[j+1];
                if(j-1 >= 0) lDiag = matrix[i][j] + prev[j-1];

                temp[j] = min(down, min(rDiag, lDiag));
            }

            prev = temp;
        }

        for(int i = 0 ; i < n ; i++)
            minVal = min(minVal, prev[i]);

        return minVal;
    }
};
