#include <iostream>
#include <vector>
using namespace std;

int countSmallerOrEqual(vector<int> &row, int num) {
  int start = 0, end = row.size() - 1;

  while (start <= end) {
    int mid = (start + end) / 2;
    if (row[mid] <= num)
      start = mid + 1;
    else
      end = mid - 1;
  }

  return start;
}

int median(vector<vector<int>> &mat, int n, int m) {

  int start = 0, end = 1e9;

  while (start <= end) {
    int mid = (start + end) / 2;
    int count = 0;
    for (int i = 0; i < n; i++) {
      count += countSmallerOrEqual(mat[i], mid);
    }

    if (count <= (n * m) / 2)
      start = mid + 1;
    else
      end = mid - 1;
  }

  return start;
}

int main() {
  vector<vector<int>> mat = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
  int n = 3, m = 3;
  cout << median(mat, n, m) << endl;
  return 0;
}
