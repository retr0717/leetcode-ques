#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int missingNumber(vector<int> &nums) {

    int sum = 0;
    for (int item : nums)
      sum += item;

    int dig = (nums.size() * (nums.size() + 1)) / 2;

    return (dig - sum);
  }
};

int main() {
  vector<int> nums = {3, 0, 1};
  Solution sol;
  cout << sol.missingNumber(nums) << "\n";
  return 0;
}
