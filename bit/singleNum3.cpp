#include <bits/stdc++.h>
using namespace std;

vector<int> singleNum(vector<int> &nums) {
  long xorSum = 0;
  for (int i = 0; i < nums.size(); i++) {
    xorSum ^= nums[i];
  }

  int rightMost = (xorSum & (xorSum - 1)) & xorSum;

  int b1 = 0, b2 = 0;

  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] & rightMost) {
      b1 ^= nums[i];
    } else {
      b2 ^= nums[i];
    }
  }

  return {b1, b2};
}

int main() {
  vector<int> nums = {3, 2, 2, 1, 8, 1};

  vector<int> result = singleNum(nums);

  cout << result[0] << " " << result[1] << endl;

  return 0;
}
