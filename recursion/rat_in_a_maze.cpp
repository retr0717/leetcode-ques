#include <bits/stdc++.h>
using namespace std;

void solve(int i, int j, vector<vector<int>> &arr, vector<string> &ans,
           vector<vector<int>> &visited, string s, int n) {
  if (i == n - 1 && j == n - 1) {
    ans.push_back(s);
    return;
  }

  // down
  if (i + 1 < n && !visited[i + 1][j] && arr[i + 1][j] == 1) {
    visited[i][j] = 1;
    solve(i + 1, j, arr, ans, visited, s + 'D', n);
    visited[i][j] = 0;
  }

  // left
  if (j - 1 >= 0 && !visited[i][j - 1] && arr[i][j - 1] == 1) {
    visited[i][j] = 1;
    solve(i, j - 1, arr, ans, visited, s + 'L', n);
    visited[i][j] = 0;
  }

  // right
  if (j + 1 < n && !visited[i][j + 1] && arr[i][j + 1] == 1) {
    visited[i][j] = 1;
    solve(i, j + 1, arr, ans, visited, s + 'R', n);
    visited[i][j] = 0;
  }

  // up
  if (i - 1 >= 0 && !visited[i - 1][j] && arr[i - 1][j] == 1) {
    visited[i][j] = 1;
    solve(i - 1, j, arr, ans, visited, s + 'U', n);
    visited[i][j] = 0;
  }
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
  vector<string> ans;
  vector<vector<int>> visited(n, vector<int>(n, 0));
  if (arr[0][0] == 1)
    solve(0, 0, arr, ans, visited, "", n);
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> arr(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  vector<string> ans = searchMaze(arr, n);
  for (string s : ans) {
    cout << s << endl;
  }
  return 0;
}
