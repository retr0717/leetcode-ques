#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int> &nums) {

    int prevCount = 0;
    int count = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 1) {
        count++;
      } else {
        count = 0;
      }

      if (prevCount < count) {
        prevCount = count;
      }
    }

    return prevCount;
  }
};

int main() {
  vector<int> nums = {1, 1, 0, 1, 1, 1};
  Solution sol;
  cout << sol.findMaxConsecutiveOnes(nums) << "\n";
  return 0;
}
