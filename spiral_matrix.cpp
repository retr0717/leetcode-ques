#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> result;
    if (matrix.empty())
      return result;
    int n = matrix.size();
    int m = matrix[0].size();
    int left = 0, right = m - 1, top = 0, bottom = n - 1;

    while (left <= right && top <= bottom) {

      // move from left to right.
      for (int i = 0; i <= right; i++) {
        result.push_back(matrix[top][i]);
      }

      top++;

      // move from top to bottom.
      for (int i = top; i <= bottom; i++) {
        result.push_back(matrix[i][right]);
      }

      right--;

      if (top <= bottom) {
        // move from right to left.
        for (int i = right; i >= left; i--) {
          result.push_back(matrix[bottom][i]);
        }

        bottom--;
      }

      // move from bottom to top.
      if (left <= right) {
        for (int i = bottom; i >= top; i--) {
          result.push_back(matrix[i][left]);
        }
        left++;
      }
    }
  }
};

int main() {
  Solution sol;
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<int> result = sol.spiralOrder(matrix);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  return 0;
}
