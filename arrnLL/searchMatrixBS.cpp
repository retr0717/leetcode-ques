#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &mat, int target) {

  int start = 0;
  int n = mat.size(), m = mat[0].size();
  int end = (n * m) - 1;

  while (start <= end) {
    int mid = (start + end) / 2;
    int row = mid / m;
    int col = mid % m;
    if (mat[row][col] == target)
      return true;
    else if (mat[row][col] < target)
      start = mid + 1;
    else
      end = mid - 1;
  }

  return false;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> matrix(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> matrix[i][j];
  int target;
  cin >> target;
  cout << searchMatrix(matrix, target) << endl;
  return 0;
}
