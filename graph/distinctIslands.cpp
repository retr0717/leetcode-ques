
#include <bits/stdc++.h>
using namespace std;

void bfs(int row, int col, vector<vector<int>> &visited, int **arr, int n,
         int m) {
  visited[row][col] = 1;
  queue<pair<int, int>> q;
  q.push({row, col});

  while (!q.empty()) {
    int row = q.front().first;
    int col = q.front().second;
    q.pop();

    // check all direcions.
    for (int delRow = -1; delRow <= 1; delRow++) {
      for (int delCol = -1; delCol <= 1; delCol++) {
        int nRow = row + delRow;
        int nCol = col + delCol;

        // check for boundary cases.
        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
            arr[nRow][nCol] == 1 && !visited[nRow][nCol]) {
          visited[nRow][nCol] = 1;
          q.push({nRow, nCol});
        }
      }
    }
  }
}

int getTotalIslands(int **arr, int n, int m) {
  vector<vector<int>> visited(n, vector<int>(m, 0));
  int count = 0;
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < m; col++) {
      if (!visited[row][col] && arr[row][col] == 1) {
        count++;
        bfs(row, col, visited, arr, n, m);
      }
    }
  }

  return count;
}
