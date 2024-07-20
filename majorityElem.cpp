#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &nums) {

    std::unordered_map<int, int> freq;

    for (const int &c : nums) {
      freq[c]++;
    }

    int n = nums.size() / 2;

    for (auto &i : freq) {
      if (i.second > n) {
        return i.first;
      }
    }

    return {};
  }
};

int main() {
  vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
  Solution sol;
  cout << sol.majorityElement(nums) << "\n";
  return 0;
}
