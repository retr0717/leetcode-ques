#include <bits/stdc++.h>
using namespace std;

void matrixRprWeighted() {
  int n, m;

  cin >> n >> m;
  int adj[n + 1][m + 1];

  for (int i = 0; i < m; i++) {
    int u, v, wt;
    cin >> u >> v >> wt;

    adj[u][v] = wt;
    adj[v][u] = wt;
  }
}

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

void adjListWeighted() {
  int n, m;

  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v, wt;
    cin >> u >> v >> wt;

    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
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
