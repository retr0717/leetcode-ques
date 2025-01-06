#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numEnclaves(vector<vector<int>> &grid) {
    queue<pair<int, int>> q;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
          if (grid[i][j] == 1) {
            q.push({i, j});
            visited[i][j] = 1;
          }
        }
      }
    }

    int dRow[] = {-1, 0, 1, 0};
    int dCol[] = {0, 1, 0, -1};

    while (!q.empty()) {
      int row = q.front().first;
      int col = q.front().second;
      q.pop();

      for (int i = 0; i < 4; i++) {
        int nRow = row + dRow[i];
        int nCol = col + dCol[i];

        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
            !visited[nRow][nCol] && grid[nRow][nCol] == 1) {
          q.push({nRow, nCol});
          visited[nRow][nCol] = 1;
        }
      }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1 && !visited[i][j])
          count++;
      }
    }

    return count;
  }
};
