#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long numDistinct(string s, string t) {
        long n = s.size();
        long m = t.size();
        vector<unsigned long long> prev(m+1, 0), curr(m+1, 0);

        prev[0] = curr[0] = 1;

        for(int i = 1; i <= n ; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s[i-1] == t[j-1])
                    curr[j] = prev[j-1] + prev[j];
                else
                    curr[j] = prev[j];
            }

            prev = curr;
        }

        return prev[m];
    }
};
