#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int count(vector<int> &nums, int goal, int n) {
    if (goal < 0)
      return 0;

    int l, r, maxCount;
    l = r = maxCount = 0;
    int sum = 0;

    while (r < n) {
      sum += (nums[r] % 2);

      while (sum > goal) {
        sum -= (nums[l] % 2);
        l++;
      }

      maxCount += (r - l + 1);
      r++;
    }

    return maxCount;
  }
  int numberOfSubarrays(vector<int> &nums, int k) {
    return count(nums, k, nums.size()) - count(nums, k - 1, nums.size());
  }
};
