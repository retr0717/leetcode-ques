#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int UpperBound(vector<int> &nums, int target) {
    int start = 0, end = nums.size() - 1, mid = 0, ans = -1;
    while (start <= end) {
      mid = (start + end) / 2;
      if (nums[mid] > target) {
        ans = mid;
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }
    return ans;
  }
};

int main() {
  vector<int> nums = {1, 2, 8, 10, 11, 12, 19};
  int target = 5;
  Solution s;
  cout << s.UpperBound(nums, target) << endl;

  // using stl.
  int index = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
  cout << index << endl;
  return 0;
}
