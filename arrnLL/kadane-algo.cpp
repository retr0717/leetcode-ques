#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    long long prevSum = LONG_MIN, sum = 0;

    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];

      if (sum > prevSum) {
        prevSum = sum;
      }

      if (sum < 0) {
        sum = 0;
      }
    }

    return prevSum;
  }
};
int main() {
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

  Solution sol;
  int sum = sol.maxSubArray(nums);
  cout << sum << "\n" << endl;
}
