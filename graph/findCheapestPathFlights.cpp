#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    // create adj list.
    vector<pair<int, int>> adj[n];
    for (auto it : flights)
      adj[it[0]].push_back({it[1], it[2]});

    // priority queue.
    //{stops, {node, dist}}
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});

    // distance vector.
    vector<int> dist(n, 1e9);
    dist[src] = 0;

    // traverse adjNodes.
    while (!q.empty()) {
      auto it = q.front();
      q.pop();

      int stops = it.first;
      int node = it.second.first;
      int price = it.second.second;

      // check for K.
      if (stops > k)
        continue;

      // check if the stops are less than the previous one.
      for (auto iter : adj[node]) {
        int adjNode = iter.first;  // node
        int edPrice = iter.second; // cost from node to adjNode.(edge weight).

        if (edPrice + price < dist[adjNode] && stops <= k) {
          dist[adjNode] = edPrice + price;
          q.push({stops + 1, {adjNode, edPrice + price}});
        }
      }
    }

    // no route. no price.
    if (dist[dst] == 1e9)
      return -1;

    // found the min price
    return dist[dst];
  }
};
