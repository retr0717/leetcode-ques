#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool checkPos(string &s1, string &s2)
    {
        if(s1.size() != 1 + s2.size()) return false;

        int first = 0;
        int second = 0;

        while(first < s1.size())
        {
            if(s1[first] == s2[second])
            {
                first++;
                second++;
            }
            else
            {
                first++;
            }
        }

        if(first == s1.size() && second == s2.size()) return true;
        return false;
    }

    static bool comparator(string &s1, string &s2)
    {
        return s1.size() < s2.size();
    }

public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 0;
        sort(words.begin(), words.end(), comparator);

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < i ; j++)
            {
                if(checkPos(words[i], words[j]) && 1 + dp[j] > dp[i])
                {
                    dp[i] = dp[j] + 1;
                }
            }

            if(dp[i] > maxi)
                maxi = dp[i];
        }

        return maxi;
    }
};

