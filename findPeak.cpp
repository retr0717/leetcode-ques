#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findPeakElement(vector<int> &nums) {

    if (nums.size() == 1)
      return 0;
    else if (nums[0] > nums[1])
      return 0;
    else if (nums[nums.size() - 1] > nums[nums.size() - 2])
      return nums.size() - 1;

    int start = 1, end = nums.size() - 2;

    while (start <= end) {
      int mid = (start + end) / 2;
      if ((nums[mid] > nums[mid - 1]) && (nums[mid] > nums[mid + 1]))
        return mid;
      else if (nums[mid] > nums[mid - 1] && nums[mid + 1] > nums[mid])
        start = mid + 1;
      else
        end = mid - 1;
    }

    return nums[start];
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 2, 3, 1};
  cout << s.findPeakElement(nums) << endl;
  return 0;
}
