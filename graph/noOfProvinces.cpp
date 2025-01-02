#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void dfs(vector<vector<int>> &adj, vector<int> &visited, int i) {
    visited[i] = 1;
    for (int it : adj[i]) {
      if (!visited[it]) {
        dfs(adj, visited, it);
      }
    }
  }

  int findCircleNum(vector<vector<int>> &isConnected) {
    int v = isConnected.size();
    vector<vector<int>> adj(v);

    for (int i = 0; i < v; i++) {
      for (int j = 0; j < v; j++) {
        if (isConnected[i][j] == 1 && i != j) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }

    vector<int> visited(v, 0);
    int count = 0;

    for (int i = 0; i < v; i++) {
      if (!visited[i]) {
        count++;
        dfs(adj, visited, i);
      }
    }

    return count;
  }
};
