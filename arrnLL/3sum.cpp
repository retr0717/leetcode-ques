#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      if (i != 0 && nums[i] == nums[i - 1])
        continue;

      int j = i + 1, k = n - 1;

      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];

        if (sum < 0) {
          j++;
        } else if (sum > 0) {
          k--;
        } else {
          vector<int> temp = {nums[i], nums[j], nums[k]};
          ans.push_back(temp);

          k--;
          j++;

          while (nums[j] == nums[j - 1] && j < k)
            j++;
          while (nums[k] == nums[k + 1] && j < k)
            k--;
        }
      }
    }

    return ans;
  }
};

int main() {
  vector<int> input = {-1, 0, 1, 2, -1, -4};
  Solution sol;
  vector<vector<int>> ans = sol.threeSum(input);
  for (auto i : ans) {
    cout << " [ " << i << " ] " << endl;
  }

  return 0;
}
