#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {

    vector<int> ans;
    stack<int> st;
    unordered_map<int, int> nextGreaterMap;

    int len = nums2.size();

    for (int i = len - 1; i >= 0; i--) {
      while (!st.empty() && nums2[i] >= st.top())
        st.pop();

      if (st.empty())
        nextGreaterMap[nums2[i]] = -1;
      else
        nextGreaterMap[nums2[i]] = st.top();

      st.push(nums2[i]);
    }

    for (int num : nums1) {
      ans.push_back(nextGreaterMap[num]);
    }

    return ans;
  }
};
