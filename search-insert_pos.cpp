#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int ans = 0, mid = 0, start = 0, end = nums.size() - 1;

    while (start <= end) {
      mid = (start + end) / 2;
      if (nums[mid] >= target) {
        ans = mid;
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }

    if (target > nums[nums.size() - 1]) {
      return nums.size();
    }

    return ans;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 3, 5, 6};
  int target = 5;
  cout << s.searchInsert(nums, target) << endl;
  return 0;
}
