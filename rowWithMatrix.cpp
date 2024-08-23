#include <iostream>
#include <vector>
using namespace std;

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
  int count = 0, maxi = -1, index = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == 1)
        count++;
    }

    if (maxi < count && count != 0) {
      index = i;
      maxi = count;
    }
    count = 0;
  }

  if (maxi == -1)
    return maxi;

  return index;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> matrix(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> matrix[i][j];
  cout << rowWithMax1s(matrix, n, m) << endl;
  return 0;
}
