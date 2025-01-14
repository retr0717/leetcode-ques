//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  void dfs(int val, vector<vector<int>> &adj, int visited[],
           vector<int> &list) {
    visited[val] = 1;
    list.push_back(val);

    for (auto it : adj[val]) {
      if (!visited[it])
        dfs(val, adj, visited, list);
    }
  }
  // Function to return a list containing the DFS traversal of the graph.
  vector<int> dfsOfGraph(< vector<int> & adj) {
    int n = adj.size();
    int visited[n] = {0};
    int start = 0;
    vector<int> list;

    dfs(start, adj, visited, list);

    return list;
  }
};

//{ Driver Code Starts.

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(
        V); // Use vector of vectors instead of array of vectors.

    for (int i = 0; i < E; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    Solution obj;
    vector<int> ans = obj.dfsOfGraph(adj);
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
    cout << "~" << endl;
  }
  return 0;
}

// } Driver Code Ends
