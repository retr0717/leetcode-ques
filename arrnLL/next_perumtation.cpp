#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int dipIndex = -1;
    int n = nums.size();
    // find the dip index by findig the smallest no from the end which is
    // greater than the no at the end
    for (int i = n - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1]) {
        dipIndex = i;
        break;
      }
    }

    // if no dip is found that means it it the last number, so just reverse the
    // value to get the next permutation.
    if (dipIndex == -1) {
      reverse(nums.begin(), nums.end());
      return;
    }

    // find the smallest value greater then the dip value but smaller than the
    // rest of the values after the dip index.
    for (int i = n - 1; i > dipIndex; i--) {
      if (nums[i] > nums[dipIndex]) {
        swap(nums[i], nums[dipIndex]);
        break;
      }
    }

    // reverse the values after the dip index to the end.
    reverse(nums.begin() + dipIndex + 1, nums.end());
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 2, 3};
  s.nextPermutation(nums);
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  return 0;
}
