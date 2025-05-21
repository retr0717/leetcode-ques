#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &edges) {
    vector<pair<pair<int, int>, int>> mst;
    vector<bool> visited(n + 1, false);  // 1-based indexing
    vector<int> minWeight(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);

    minWeight[1] = 0; // Start from node 1

    for (int count = 1; count <= n; ++count) {
        int u = -1;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i] && (u == -1 || minWeight[i] < minWeight[u])) {
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = true;

        for (auto &edge : edges) {
            int a = edge.first.first;
            int b = edge.first.second;
            int w = edge.second;

            int v = -1;
            if (a == u && !visited[b]) v = b;
            else if (b == u && !visited[a]) v = a;

            if (v != -1 && w < minWeight[v]) {
                minWeight[v] = w;
                parent[v] = u;
            }
        }
    }

    for (int v = 1; v <= n; ++v) {
        if (parent[v] != -1) {
            mst.push_back({{parent[v], v}, minWeight[v]});
        }
    }

    return mst;
}
