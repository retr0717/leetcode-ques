#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  void dfs(int row, int col, vector<vector<int>> &visited,
           vector<vector<char>> &board, int dRow[], int dCol[], int n, int m) {
    visited[row][col] = 1;

    for (int i = 0; i < 4; i++) {
      int nRow = row + dRow[i];
      int nCol = col + dCol[i];

      if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
          !visited[nRow][nCol] && board[nRow][nCol] == 'O') {
        dfs(nRow, nCol, visited, board, dRow, dCol, n, m);
      }
    }
  }

public:
  void solve(vector<vector<char>> &board) {
    vector<vector<char>> backup = board;

    int n = board.size();
    int m = board[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0));

    int dRow[] = {-1, 0, 1, 0};
    int dCol[] = {0, 1, 0, -1};

    // top and bottom row.
    for (int j = 0; j < m; j++) {
      if (!visited[0][j] && board[0][j] == 'O') {
        dfs(0, j, visited, board, dRow, dCol, n, m);
      }

      if (!visited[n - 1][j] && board[n - 1][j] == 'O') {
        dfs(n - 1, j, visited, board, dRow, dCol, n, m);
      }
    }

    // left and right col.
    for (int j = 0; j < n; j++) {
      if (!visited[j][0] && board[j][0] == 'O') {
        dfs(j, 0, visited, board, dRow, dCol, n, m);
      }

      if (!visited[j][m - 1] && board[j][m - 1] == 'O') {
        dfs(j, m - 1, visited, board, dRow, dCol, n, m);
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!visited[i][j] && board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }
  }
};
