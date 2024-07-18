#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int xorSum = 0;

    for (int num : nums) {
      xorSum ^= num;
    }

    return xorSum;
  }
};

int main() {
  vector<int> nums = {4, 1, 2, 1, 2};
  Solution sol;
  cout << sol.singleNumber(nums) << "\n";
  return 0;
}
