#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    stack<int> st;
    vector<int> ans;

    int n = nums.size();

    for (int i = (2 * n) - 1; i >= 0; i--) {
      while (!st.empty() && st.top() <= nums[i % n])
        st.pop();

      if (i < n) {
        st.empty() ? ans.push_back(-1) : ans.push_back(st.top());
      }

      st.push(nums[i % n]);
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> arr = {2, 1, 4, 3};
  vector<int> ans = s.nextGreaterElements(arr);

  for (auto x : ans)
    cout << x << " ";

  return 0;
}
