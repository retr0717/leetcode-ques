#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    stack<int> st;
    int pse = 0, nse = 0, element = 0;
    int maxArea = 0;
    for (int i = 0; i < heights.size(); i++) {
      while (!st.empty() && heights[st.top()] > heights[i]) {
        element = st.top();
        st.pop();
        nse = i;
        pse = st.empty() ? -1 : st.top();
        maxArea = max(maxArea, heights[element] * (nse - pse - 1));
      }

      st.push(i);
    }

    while (!st.empty()) {
      nse = heights.size();
      element = st.top();
      st.pop();
      pse = st.empty() ? -1 : st.top();
      maxArea = max(maxArea, heights[element] * (nse - pse - 1));
    }

    return maxArea;
  }
};
