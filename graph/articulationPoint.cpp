#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  private:
    int timer = 0;

    void dfs(int node, int parent,
             vector<int> &vis,
             int tin[], int low[],
             vector<int> &mark,
             vector<int> adj[]) {
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        int children = 0;

        for (int it : adj[node]) {
            if (it == parent) continue;

            if (!vis[it]) {
                dfs(it, node, vis, tin, low, mark, adj);
                low[node] = min(low[node], low[it]);

                // Mark non-root articulation point
                if (low[it] >= tin[node] && parent != -1)
                    mark[node] = 1;
                
                children++;
            } else {
                // Back edge to ancestor
                low[node] = min(low[node], tin[it]);
            }
        }

        // Mark root articulation point
        if (parent == -1 && children > 1)
            mark[node] = 1;
    }

  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> vis(V, 0), mark(V, 0);
        int tin[V], low[V];
        timer = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i])
                dfs(i, -1, vis, tin, low, mark, adj);
        }

        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (mark[i])
                ans.push_back(i);
        }

        if (ans.empty())
            return {-1};

        return ans;
    }
};

