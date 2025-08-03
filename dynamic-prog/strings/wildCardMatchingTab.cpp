#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();

        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        dp[0][0] = true;
        for(int i = 1 ; i <= m ; i++)
            dp[0][i] = false;
        
         for( int j = 1 ; j <= n ; j++) {
            bool flag = true;
            for(int c = 1 ; c <= j ; c++)
            {
                if(p[c-1] != '*') {
                    flag = false;
                    break;
                }
            }

            dp[j][0] = flag;
        }

        for(int i = 1; i <= n ; i++)
        {
            for(int j = 1 ; j <= m ; j++)
            {
                if(s[j-1] == p[i-1] || p[i-1] == '?') dp[i][j] = dp[i-1][j-1];
                else if(p[i-1] == '*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
};
