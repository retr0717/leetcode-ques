#include <bits/stdc++.h>
using namespace std;
/*class Graph
{

public:
        int V;
    list<int> *adj;
    */

bool detect(int src, int parent, list<int> adj[], int visited[]) {
  visited[src] = 1;

  for (auto it = adj[src].begin(); it != adj[src].end(); ++it) {
    if (!visited[*it]) {
      if (detect(*it, src, adj, visited) == true)
        return true;
    } else if (parent != *it) {
      return true;
    }
  }

  return false;
}

bool isCyclic(Graph g) {

  int visited[g.V] = {0};

  for (int i = 0; i < g.V; i++) {
    if (!visited[i]) {
      if (detect(i, -1, g.adj, visited))
        return true;
    }
  }
  return false;
}
