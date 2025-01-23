#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  bool boundaryCheck(int row, int col, int rowLimit, int colLimit) {
    return (row >= 0 && row < rowLimit && col >= 0 && col < colLimit);
  }

public:
  int minimumEffortPath(vector<vector<int>> &heights) {
    int n = heights.size();
    int m = heights[0].size();

    // priority queue {diff, {row, col}}.
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;

    vector<vector<int>> dist(n, vector<int>(m, 1e9));

    dist[0][0] = 0;
    pq.push({0, {0, 0}});
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while (!pq.empty()) {
      auto it = pq.top();
      pq.pop();
      int diff = it.first;
      int row = it.second.first;
      int col = it.second.second;

      // end
      if (row == n - 1 && col == m - 1)
        return diff;

      // traverse in all four directions from a single cell.
      for (int i = 0; i < 4; i++) {
        int newRow = row + dr[i];
        int newCol = col + dc[i];

        // boundary check.
        if (boundaryCheck(newRow, newCol, n, m)) {
          int newEffort =
              max(abs(heights[row][col] - heights[newRow][newCol]), diff);
          if (newEffort < dist[newRow][newCol]) {
            dist[newRow][newCol] = newEffort;
            pq.push({newEffort, {newRow, newCol}});
          }
        }
      }
    }

    return 0;
  }
};
