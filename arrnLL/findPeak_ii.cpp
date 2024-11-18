#include <iostream>
#include <vector>
using namespace std;
int findRow(vector<vector<int>> &mat, int n, int col) {
  int index = -1;
  int maxi = -1;
  for (int i = 0; i < n; i++) {
    if (mat[i][col] > maxi) {
      maxi = mat[i][col];
      index = i;
    }
  }

  return index;
}

vector<int> findPeakGrid(vector<vector<int>> &g) {
  int n = g.size(), m = g[0].size();

  int start = 0;
  int end = m - 1;

  while (start <= end) {
    int mid = (start + end) / 2;
    int row = findRow(g, n, mid);
    int left = mid - 1 >= 0 ? g[row][mid - 1] : -1;
    int right = mid + 1 < m ? g[row][mid + 1] : -1;

    if (g[row][mid] > left && g[row][mid] > right)
      return {row, mid};
    else if (g[row][mid] < left)
      end = mid - 1;
    else
      start = mid + 1;
  }

  return {-1, -1};
}

int main() {
  vector<vector<int>> g = {{1, 2, 3, 4, 5},
                           {6, 7, 8, 9, 10},
                           {11, 12, 13, 14, 15},
                           {16, 17, 18, 19, 20},
                           {21, 22, 23, 24, 25}};
  vector<int> res = findPeakGrid(g);
  std::cout << res[0] << " " << res[1] << std::endl;
  return 0;
}
