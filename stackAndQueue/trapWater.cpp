#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    int n = height.size();
    int totWater = 0, leftMax = 0, rightMax = 0;
    int r = n - 1, l = 0;

    // find the water capacity.
    while (l < r) {
      if (height[l] <= height[r]) {
        if (leftMax > height[l])
          totWater += (leftMax - height[l]);
        else
          leftMax = height[l];
        l += 1;
      } else {
        if (rightMax > height[r])
          totWater += (rightMax - height[r]);
        else
          rightMax = height[r];
        r -= 1;
      }
    }

    return totWater;
  }
};
