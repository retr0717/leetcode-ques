//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User Function Template
class Solution {
public:
  // Function to find the shortest distance of all the vertices
  // from the source vertex src.
  vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
    // create a graph.
    int n = adj.size();

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    vector<int> dist(n, 1e9); // Initialize distances with a large value
    dist[src] = 0;
    pq.push({0, src}); // Push the source node with distance 0

    while (!pq.empty()) {
      auto it = pq.top();
      int node = it.second;
      int dis = it.first;
      pq.pop();

      // Loop through all the adjacent nodes
      for (auto it : adj[node]) {
        int adjNode = it.first;
        int edW = it.second;
        if (dis + edW < dist[adjNode]) {
          dist[adjNode] = dis + edW;
          pq.push({dis + edW, adjNode});
        }
      }
    }

    // Return the shortest distances from the source to all nodes
    return dist;

    // if(dist[n] == 1e9) return {-1};
    // vector<int> path;
    // int node = src;
    // while(parent[node] != node)
    // {
    //     path.push_back(node);
    //     node = parent[node];
    // }
    // path.push_back(1);
    // reverse(path.begin(), path.end());
    // return path;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> adj(V);
    int i = 0;
    while (i++ < E) {
      int u, v, w;
      cin >> u >> v >> w;
      pair<int, int> t1 = {v, w}, t2 = {u, w};
      adj[u].push_back(t1);
      adj[v].push_back(t2);
    }
    int src;
    cin >> src;
    cin.ignore();

    Solution obj;
    vector<int> res = obj.dijkstra(adj, src);

    for (int i = 0; i < V; i++)
      cout << res[i] << " ";
    cout << endl;

    cout << "~" << "\n";
  }

  return 0;
}
// } Driver Code Ends
