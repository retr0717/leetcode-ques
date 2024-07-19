#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {

    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++) {
      if (map.find(target - nums[i]) != map.end()) {
        return {map[target - nums[i]], i};
      }
      map[nums[i]] = i;
    }

    return {};
  }
};

int main() {
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  Solution sol;
  vector<int> result = sol.twoSum(nums, target);
  for (auto i = result.begin(); i != result.end(); i++) {
    cout << *i << "  ";
  }
  cout << "\n";
  return 0;
}
