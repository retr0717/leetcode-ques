#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestOnes(vector<int> &nums, int k) {
    int maxLen, l, r, zeros;
    l = zeros = r = 0;
    maxLen = 0;

    while (r < nums.size()) {
      if (nums[r] == 0)
        zeros++;

      while (zeros > k) {
        if (nums[l] == 0)
          zeros--;
        l++;
      }

      if (zeros <= k) {
        int len = r - l + 1;
        maxLen = max(maxLen, len);
      }

      r++;
    }

    return maxLen;
  }
};
