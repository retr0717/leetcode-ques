#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int distinct(int i, int j, string s, string t)
    {
        if( j < 0 ) return 1;
        if( i < 0 ) return 0;

        if(s[i] == t[j])
            return distinct(i-1, j-1, s, t) + distinct(i-1, j , s, t);
        else
            return distinct(i-1, j, s, t);
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        return distinct(n-1, m-1, s, t);
    }
};
