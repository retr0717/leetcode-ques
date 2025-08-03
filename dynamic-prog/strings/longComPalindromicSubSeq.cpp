#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        if(n == 1 && m == 1)
        {
            if(text1[0] != text2[0]) return 0;
        }

        vector<int> prev(m+1, 0), curr(m+1, 0);

        for(int j = 0 ; j < m ; j++) prev[j] = 0;

        for(int i = 1; i <= n ; i++)
        {
            for(int j = 1 ; j <= m ; j++)
            {
                //match found.
                if(text1[i-1] == text2[j-1]) 
                    curr[j] = 1 + prev[j-1];
                else
                    curr[j] = 0 + max(prev[j], curr[j-1]);//not a match.
            }

            prev = curr;
        }

        return prev[m];
    }

public:
    int longestPalindromeSubseq(string s) {

        string t = s;
        reverse(t.begin(), t.end());

        return longestCommonSubsequence(s, t);
    }
};
