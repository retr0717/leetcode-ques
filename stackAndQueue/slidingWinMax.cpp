#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> queue;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
      if (!queue.empty() && queue.front() <= i - k)
        queue.pop_front();

      while (!queue.empty() && nums[queue.back()] <= nums[i])
        queue.pop_back();

      queue.push_back(i);

      if (i >= k - 1)
        result.push_back(nums[queue.front()]);
    }

    return result;
  }
};
