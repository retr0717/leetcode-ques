#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool f(int i, int j , string &s, string &p, vector<vector<int>> &dp)
    {
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0) return false;
        if( j < 0 && i >= 0) {
            for(int c = 0 ; c <= i ; c++)
            {
                if(p[c] != '*') return false;
            }

            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[j] == p[i] || p[i] == '?') return dp[i][j] = f(i-1, j-1, s, p, dp);

        if(p[i] == '*') return dp[i][j] = f(i-1, j, s, p, dp) || f(i, j-1, s, p, dp);

        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return f(n-1, m-1, s, p, dp);
    }
};
