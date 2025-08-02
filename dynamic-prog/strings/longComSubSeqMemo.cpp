#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int maxSeq(int ind1, int ind2, string text1, string text2, vector<vector<int>>& dp)
    {
        if(ind1 < 0 || ind2 < 0) return 0;

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        //match found.
        if(text1[ind1] == text2[ind2]) return dp[ind1][ind2] = 1 + maxSeq(ind1-1, ind2-1, text1, text2, dp);

        //not a match.
        return dp[ind1][ind2] = 0 + max(maxSeq(ind1-1, ind2, text1, text2, dp), maxSeq(ind1, ind2-1, text1, text2, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n, vector<int> (m, -1));

        return maxSeq(n-1, m-1, text1, text2, dp);
    }
};
