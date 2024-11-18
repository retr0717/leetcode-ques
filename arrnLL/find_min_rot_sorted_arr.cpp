#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums) {
    int start = 0, end = nums.size() - 1, ans = INT_MAX;
    while (start <= end) {
      int mid = (start + end) / 2;
      if (nums[start] <= nums[mid]) {
        ans = min(ans, nums[start]);
        start = mid + 1;
      } else {
        if (nums[mid] <= nums[end]) {
          ans = min(ans, nums[mid]);
          end = mid - 1;
        }
      }
    }

    return ans;
  }
};

int main() {
  vector<int> nums = {3, 4, 5, 1, 2};
  Solution sol;
  int min = sol.search(nums);
  cout << min << endl;
}
