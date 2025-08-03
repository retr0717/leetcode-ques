#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(int i, int j, string word1, string word2)
    {
        if( i < 0) return j+1;
        if( j < 0) return i+1;

        if(word1[i] == word2[j]) return f(i-1, j-1, word1, word2);

        return 1 + min(f(i-1, j, word1, word2), min(f(i, j-1, word1, word2), f(i-1, j-1, word1, word2)));
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        return f(n-1, m-1, word1, word2);
    }
};
