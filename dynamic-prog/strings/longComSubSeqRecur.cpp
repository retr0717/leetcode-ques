#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int maxSeq(int ind1, int ind2, string text1, string text2)
    {
        if(ind1 < 0 || ind2 < 0) return 0;

        //match found.
        if(text1[ind1] == text2[ind2]) return 1 + maxSeq(ind1-1, ind2-1, text1, text2);

        //not a match.
        return 0 + max(maxSeq(ind1-1, ind2, text1, text2), maxSeq(ind1, ind2-1, text1, text2));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        return maxSeq(n-1, m-1, text1, text2);
    }
};
