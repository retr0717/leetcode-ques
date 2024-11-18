#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool search(vector<int> &nums, int target) {
    int start = 0, end = nums.size() - 1;

    while (start <= end) {
      int mid = (start + end) / 2;
      if (nums[mid] == target) {
        return true;
      }

      if (nums[start] == nums[mid] && nums[mid] == nums[end]) {
        end--;
        start++;
        continue;
      } else if (nums[start] <= nums[mid]) {
        if (nums[start] <= target && target <= nums[mid])
          end = mid - 1;
        else
          start = mid + 1;
      } else {
        if (nums[mid] <= target && target <= nums[end])
          start = mid + 1;
        else
          end = mid - 1;
      }
    }

    return false;
  }
};

int main() {
  vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
  Solution sol;
  bool result = sol.search(nums, 0);
}
