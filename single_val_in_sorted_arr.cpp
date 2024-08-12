#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int singleNonDuplicate(vector<int> &nums) {
    // edge cases.
    int start = 0, end = nums.size() - 1;

    if (nums.size() == 1)
      return nums[start];
    else if (nums[start] != nums[start + 1])
      return nums[start];
    else if (nums[end] != nums[end - 1])
      return nums[end];

    start = start + 1;
    end = end - 1;

    while (start <= end) {
      int mid = (start + end) / 2;
      if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
        return nums[mid];
      else if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
               (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
        start = mid + 1;
      else
        end = mid - 1;
    }

    return nums[start];
  }
};

int main() {

  Soluti Solution s;
  vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
  cout << s.singleNonDuplicate(nums) << endl;
  return 0;
}
