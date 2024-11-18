#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {

    int j = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != 0) {
        nums[j] = nums[i];
        j++;
      }
    }

    for (j; j < nums.size(); j++) {
      nums[j] = 0;
    }
  }
};

int main() {
  vector<int> nums = {0, 1, 0, 3, 12};
  Solution sol;
  sol.moveZeroes(nums);
  for (auto i = nums.begin(); i != nums.end(); i++) {
    cout << *i << "  ";
  }
  cout << "\n";
  return 0;
}
