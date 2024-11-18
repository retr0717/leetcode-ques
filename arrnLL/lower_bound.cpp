
#include <algorithm> // For std::lower_bound
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int LowerBound(vector<int> &nums, int target) {
    int start = 0, end = nums.size() - 1;
    int ans =
        nums.size(); // Initialize to the size of the array (end of the range)
    while (start <= end) {
      int mid = (start + end) / 2;
      if (nums[mid] >= target) {
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
  Solution s;
  vector<int> nums = {1, 2, 8, 10, 11, 12, 19};
  int target = 5;
  cout << s.LowerBound(nums, target) << endl;

  // Using STL.
  int index = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
  cout << index << endl;
  return 0;
}
