#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {

    int start = 0, end = nums.size() - 1;

    while (start <= end) {
      int mid = (start + end) / 2;
      if (nums[mid] == target) {
        return mid;
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

    return -1;
  }
};

int main() {
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  Solution sol;
  int index = sol.search(nums, 4);
  cout << index << endl;
}