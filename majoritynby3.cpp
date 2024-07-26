#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    std::unordered_map<int, int> freq;
    vector<int> result;

    for (int &c : nums) {
      freq[c]++;
    }

    int n = nums.size() / 3;

    for (auto &i : freq) {
      if (i.second > n) {
        result.push_back(i.first);
      }
    }

    return result;
  }
};

int main() {
  Solution s;
  vector<int> nums = {3, 2, 3};
  vector<int> result = s.majorityElement(nums);
  for (int &c : result) {
    cout << c << " ";
  }
}
