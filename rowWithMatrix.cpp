#include <iostream>
#include <vector>
using namespace std;

int LowerBound(vector<int> &nums, int target) {
  int start = 0, end = nums.size() - 1;
  int ans =
      nums.size(); // Initialize to the size of the array (end of the range)
  while (start <= end) {
    int mid = (start + end) / 2;
    if (nums[mid] >= target) {
      ans = mid;
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  return ans;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
  int count = 0, maxi = -1, index = 0;

  for (int i = 0; i < n; i++) {

    count = m - LowerBound(matrix[i], 1);

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
