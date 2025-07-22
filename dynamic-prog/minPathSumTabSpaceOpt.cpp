#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, 0);

        for(long i = 0 ; i < m ; i++)
        {
            vector<int> temp(n, 0);
            for(long j = 0 ; j < n ; j++)
            {
                if(i == 0 && j == 0) temp[j] = grid[i][j];
                else{
                        //compute all the path and find min.
                        long up = grid[i][j];
                        if(i > 0) up += prev[j];
                        else up += 1e9;

                        long left = grid[i][j];
                        if(j > 0) left += temp[j-1];
                        else left += 1e9;

                        temp[j] = min(up,left);
                }
            }

            prev = temp;
        }

        return prev[n-1];
    }
};
