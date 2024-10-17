#include <bits/stdc++.h> 

bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
  for (int k = 0; k < n; k++) {
    if (k != node && graph[k][node] == 1 && color[k] == col) {
      return false;
    }
  }
  return true;
}

bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
  if (node == N) {
    return true;
  }

  for (int i = 1; i <= m; i++) {
    if (isSafe(node, color, graph, N, i)) {
      color[node] = i;
      if (solve(node + 1, color, m, N, graph)) return true;
      color[node] = 0;
    }

  }
  return false;
}

string graphColoring(vector<vector<int>>& adjMatrix, int n, int m)
{
    bool boolMatrix[101][101];

    for (int i = 0; i < adjMatrix.size(); ++i) {
        for (size_t j = 0; j < adjMatrix[i].size(); ++j) {
            boolMatrix[i][j] = (adjMatrix[i][j] == 1);
        }
    }

    int color[n] = {0};
    if (solve(0, color, m, n, boolMatrix)) return "Yes";
    return "No";
}