#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    long long prevSum = LONG_MIN, sum = 0;
    int start = -1, end = -1, pointer = 0;
    ;

    for (int i = 0; i < nums.size(); i++) {

      if (sum == 0)
        pointer = i;

      sum += nums[i];

      if (sum > prevSum) {
        prevSum = sum;
        start = pointer;
        end = i;
      }

      if (sum < 0) {
        sum = 0;
      }
    }

    for (int i = start; i <= end; i++) {
      cout << nums[i] << " ";
    }

    return prevSum;
  }
};
int main() {
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

  Solution sol;
  long long sum = sol.maxSubArray(nums);
  cout << "\n" << sum << "\n" << endl;
}
