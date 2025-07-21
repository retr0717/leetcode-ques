#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int Path(int m, int n, vector<vector<int>> &dp)
    {
        //path exists.
        if( m == 0 && n == 0) return 1;
        
        //boundary check.
        if( m < 0 || n < 0) return 0;

        //precomputed value.
        if(dp[m][n] != -1) return dp[m][n];

        //move up and left.
        int up = Path(m-1, n, dp);
        int left = Path(m, n-1, dp);

        return dp[m][n] = (up+left);
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));

        return Path(m-1, n-1, dp);
    }
};
