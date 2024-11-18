#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {

    int r = matrix.size();
    int c = matrix[0].size();
    int m[r][c];

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        m[i][j] = matrix[i][j];
      }
    }

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (matrix[i][j] == 0) {
          for (int k = 0; k < r; k++) {
            m[k][j] = 0;
          }

          for (int k = 0; k < c; k++) {
            m[i][k] = 0;
          }
        }
      }
    }

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        matrix[i][j] = m[i][j];
      }
    }
  }
};

int main() {
  vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  Solution sol;
  sol.setZeroes(matrix);
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
