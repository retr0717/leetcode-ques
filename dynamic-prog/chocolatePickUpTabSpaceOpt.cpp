#include <bits/stdc++.h> 

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    int n = grid.size(); //row no.
    int m = grid[0].size(); //col no.

    vector<vector<int>> prev(m, vector<int> (m, 0));

    //variable ending.
    //base case.
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(i == j) prev[i][j] = grid[n-1][i];
            else prev[i][j] = grid[n-1][i] + grid[n-1][j];
        }
    }

    //try all combo.
    for(int i = n-2; i >= 0 ; i--)
    {
        vector<vector<int>> temp(m, vector<int> (m, 0));

        for(int j = 0; j < m ; j++)
        {
            for(int j2 = 0; j2 < m ; j2++)
            {
                int maxVal = -1e8;
                for(int di = -1; di <= 1; di++)
                {
                    for(int dj = -1; dj <= 1; dj++)
                    {
                        int value = 0;
                        if(j == j2) value = grid[i][j];
                        else value = grid[i][j] + grid[i][j2];

                        if(j+di >= 0 && j+di < m && j2+dj >= 0 && j2+dj < m)
                            value += prev[j+di][j2+dj];
                        else 
                            value += -1e8;
                        
                        maxVal= max(maxVal, value);
                    }
                }

                temp[j][j2] = maxVal;
            }
        }

        prev = temp;
    }

    return prev[0][m-1];
}
