#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums) {
    int start = 0, end = nums.size() - 1, ans = INT_MAX, index = -1;
    while (start <= end) {
      int mid = (start + end) / 2;
      if (nums[start] <= nums[mid]) {
        index = start;
        ans = min(ans, nums[start]);
        start = mid + 1;
      } else {
        if (nums[mid] <= nums[end]) {
          index = mid;
          ans = min(ans, nums[mid]);
          end = mid - 1;
        }
      }
    }
    cout << index << endl;
  }
};

int main() {
  vector<int> nums = {3, 4, 5, 1, 2};
  Solution sol;
  int min = sol.search(nums);
  cout << min << endl;
}
