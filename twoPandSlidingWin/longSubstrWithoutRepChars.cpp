#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    vector<int> hashMap(255, -1);

    int r, l, maxLen, n;
    maxLen = 0;
    n = s.length();
    l = 0;
    r = 0;

    while (r < n) {
      if (hashMap[s[r]] != -1) {
        if (hashMap[s[r]] >= l) {
          l = hashMap[s[r]] + 1;
        }
      }

      int len = r - l + 1;
      maxLen = max(maxLen, len);
      hashMap[s[r]] = r;
      r++;
    }

    return maxLen;
  }
};
