#include <bits/stdc++.h>
using namespace std;

void matrixRpr() {
  int n, m;

  cin >> n >> m;
  int adj[n + 1][m + 1];

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u][v] = 1;
    adj[v][u] = 1;
  }
}

void adjList() {
  int n, m;

  cin >> n >> m;
  vector<vector<int>> adj(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

void adjListDirected() {
  int n, m;

  cin >> n >> m;
  vector<vector<int>> adj(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
  }
}

int main() {
  matrixRpr();
  adjList();
  adjListDirected();
  return 0;
}
