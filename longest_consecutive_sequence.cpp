#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {

    int n = nums.size();
    if (n == 0)
      return 0;

    int longest = 1;
    unordered_set<int> st;

    for (int item : nums) {
      st.insert(item);
    }

    for (int item : st) {
      if (st.find(item - 1) == st.end()) {
        int count = 1;
        int x = item;

        while (st.find(x + 1) != st.end()) {
          x += 1;
          count += 1;
        }

        longest = max(count, longest);
      }
    }

    return longest;
  }
};

int main() {
  vector<int> nums = {100, 4, 200, 1, 3, 2};
  Solution sol;
  cout << sol.longestConsecutive(nums) << endl;
  return 0;
}
