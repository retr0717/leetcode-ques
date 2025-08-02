#include <bits/stdc++.h>
using namespace std;

int lcs(string &text1, string &text2){

    int n = text1.size();
    int m = text2.size();

    if(n == 1 && m == 1)
    {
        if(text1[0] != text2[0]) return 0;
    }

    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    int maxVal = 0;

    for(int i = 0 ; i < n ; i++) dp[i][0] = 0;
    for(int j = 0 ; j < m ; j++) dp[0][j] = 0;

    for(int i = 1; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            //match found.
            if(text1[i-1] == text2[j-1])
            { 
                dp[i][j] = 1 + dp[i-1][j-1];
                maxVal = max(maxVal, dp[i][j]);
            }
            else
                dp[i][j] = 0;//not a match.
        }
    }

    return maxVal;
}
