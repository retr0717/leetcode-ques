#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long MinPath(int m , int n, vector<vector<int>> &grid)
    {
        if( m == 0 && n == 0) return grid[0][0];
        
        if(m < 0 || n < 0) return INT_MAX;

        //compute all the path and find min.
        long up = grid[m][n] + MinPath(m-1, n, grid);
        long left = grid[m][n] + MinPath(m, n-1, grid);

        long minPrev = min(up, left);

        return minPrev;
    }
public:
    long minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        return MinPath(m-1, n-1, grid);
    }
};
