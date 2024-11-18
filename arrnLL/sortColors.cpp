#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void sortColors(vector<int> &nums) {

    int zeroCount = 0, oneCount = 0, twoCount = 0, i = 0;

    for (i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        zeroCount++;
      } else if (nums[i] == 1) {
        oneCount++;
      } else {
        twoCount++;
      }
    }

    // filling value based on the count in the order.
    for (i = 0; i < zeroCount; i++)
      nums[i] = 0;

    for (; i < (oneCount + zeroCount); i++)
      nums[i] = 1;

    for (; i < (twoCount + oneCount + zeroCount); i++)
      nums[i] = 2;
  }
};

int main() {
  std::vector<int> nums = {2, 0, 2, 1, 1, 0};
  Solution sol;
  sol.sortColors(nums);
  for (auto i = nums.begin(); i != nums.end(); i++) {
    std::cout << *i << "  ";
  }
  std::cout << "\n";
  return 0;
}
