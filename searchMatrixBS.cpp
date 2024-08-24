#include <iostream>
#include <vector>
using namespace std;

bool findFirst(vector<int> &arr, int n, int x) {
  int start = 0, end = n - 1, ans = -1;
  while (start <= end) {
    int mid = (start + end) / 2;
    if (arr[mid] == x) {
      ans = mid;
      end = mid - 1;
    } else if (x > arr[mid]) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  return ans > -1;
}

bool searchMatrix(vector<vector<int>> &mat, int target) {

  for (int i = 0; i < mat.size(); i++) {
    bool occ = findFirst(mat[i], mat[i].size(), target);
    if (occ)
      return true;
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
