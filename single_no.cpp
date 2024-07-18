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

/*
concept of XOR:
xor of same no result in 0.
a ^ a = 0

xor of 0 with any no is the no itself.
a ^ 0 = a

here the numbers having 2 occurence will become zero
which will leave the single number left to be xor with 0
which in turn will result in the single number itself.
 */
