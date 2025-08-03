#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    string longestCommonSubsequence(string text1, string text2, int n, int m) {

        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

        for(int i = 0 ; i < n ; i++) dp[i][0] = 0;
        for(int j = 0 ; j < m ; j++) dp[0][j] = 0;

        for(int i = 1; i <= n ; i++)
        {
            for(int j = 1 ; j <= m ; j++)
            {
                //match found.
                if(text1[i-1] == text2[j-1]) 
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);//not a match.
            }
        }

        string ans = "";
        int i = n, j = m;

        while(i > 0 && j > 0)
        {
                if(text1[i-1] == text2[j-1])
                {
                        ans += text1[i-1];
                        i--;
                        j--;
                }
                else if(dp[i-1][j] > dp[i][j-1]) i--;
                else j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        string lcs = longestCommonSubsequence(str1, str2, n, m);
        string result = "";

        int i = 0, j = 0;
        for(char c : lcs)
        {
            while (i < n && str1[i] != c) result += str1[i++];
            while (j < m && str2[j] != c) result += str2[j++];
            result += c;
            i++;
            j++;
        }

        while(i < n) result += str1[i++];
        while(j < m) result += str2[j++];

        return result;
    }
};
