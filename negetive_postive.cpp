#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> rearrangeArray(vector<int> &nums) {
    vector<int> positive;
    vector<int> negetive;

    // positive
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < 0)
        negetive.push_back(nums[i]);
      else if (nums[i] > 0)
        positive.push_back(nums[i]);
    }

    // join
    int j = 0;
    for (int i = 0; i < nums.size() / 2; i++) {
      nums[j] = positive[i];
      nums[j + 1] = negetive[i];
      j += 2;
    }

    return nums;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 2, 3, -4, -1, 4};
  vector<int> rearranged = sol.rearrangeArray(nums);
  for (int i = 0; i < rearranged.size(); i++) {
    cout << rearranged[i] << " ";
  }
  return 0;
}
