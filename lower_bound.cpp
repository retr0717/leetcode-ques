#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int LowerBound(vector<int> &nums, int target) {
    int start = 0, end = nums.size(), mid = 0, ans = -1;
    while (start <= end) {
      mid = (start + end) / 2;
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
  return 0;
}
