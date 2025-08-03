#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool f(int i, int j , string &s, string &p)
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

        if(s[j] == p[i] || p[i] == '?') return f(i-1, j-1, s, p);

        if(p[i] == '*') return f(i-1, j, s, p) || f(i, j-1, s, p);

        return false;
    }
public:
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();

        return f(n-1, m-1, s, p);
    }
};
