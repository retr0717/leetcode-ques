#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {

    if (s.size() == 0 || g.size() == 0)
      return 0;

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int l, r;
    l = r = 0;

    while (l < s.size() && r < g.size()) {
      if (s[l] >= g[r])
        r++;

      l++;
    }

    return r;
  }
};
