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
      sum += nums[r];

      while (sum > goal) {
        sum -= nums[l];
        l++;
      }

      maxCount += (r - l + 1);
      r++;
    }

    return maxCount;
  }

  int numSubarraysWithSum(vector<int> &nums, int goal) {
    return count(nums, goal, nums.size()) - count(nums, goal - 1, nums.size());
  }
};
