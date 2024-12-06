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

  int maximalRectangle(vector<vector<char>> &matrix) {
    vector<vector<char>> inputs = matrix;

    int row = inputs.size();
    int col = inputs[0].size();
    vector<vector<int>> prefixMat(row, vector<int>(col, 0));

    for (int i = 0; i < col; i++) {
      int sum = 0;
      for (int j = 0; j < row; j++) {
        sum = sum + 1;
        if (inputs[j][i] == '0')
          sum = 0;

        prefixMat[j][i] = sum;
      }
    }

    int maxArea = 0;
    for (int i = 0; i < row; i++) {
      maxArea = max(maxArea, largestRectangleArea(prefixMat[i]));
    }

    return maxArea;
  }
};
