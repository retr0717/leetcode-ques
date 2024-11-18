#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {

    vector<vector<int>> ans;

    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      for (int j = i + 1; j < n; j++) {

        if (j > i + 1 && nums[j] == nums[j - 1])
          continue;

        int k = j + 1;
        int l = n - 1;

        while (k < l) {
          long long sum = nums[i];
          sum += nums[j];
          sum += nums[k];
          sum += nums[l];

          if (sum == target) {
            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
            ans.push_back(temp);

            k++;
            l--;

            while (k < l && nums[k] == nums[k - 1])
              k++;
            while (k < l && nums[l] == nums[l + 1])
              l--;

          } else if (sum < target) {
            k++;
          } else {
            l--;
          }
        }
      }
    }

    return ans;
  }
};

int main() {
  vector<int> input = {1, 0, -1, 0, -2, 2};
  Solution sol;
  vector<vector<int>> ans = sol.fourSum(input, 0);

  for (auto item : ans) {
    cout << " [ " << item[0] << ", " << item[1] << " ," << item[2] << " ] ";
  }
}
