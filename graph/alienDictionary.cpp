
#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(int V, vector<vector<int>> &adj) {
  vector<int> indegree(V, 0);
  for (int i = 0; i < V; i++) {
    for (auto it : adj[i]) {
      indegree[it]++;
    }
  }

  queue<int> q;
  for (int i = 0; i < V; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  vector<int> topo;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    topo.push_back(node);

    for (auto it : adj[node]) {
      indegree[it]--;
      if (indegree[it] == 0)
        q.push(it);
    }
  }

  return topo;
}

string getAlienLanguage(vector<string> &dictionary, int k) {
  vector<vector<int>> adj(k);
  for (int i = 0; i < dictionary.size() - 1; i++) {
    string s1 = dictionary[i];
    string s2 = dictionary[i + 1];
    int len = min(s1.size(), s2.size());
    for (int ptr = 0; ptr < len; ptr++) {
      if (s1[ptr] != s2[ptr]) {
        adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
        break;
      }
    }
  }

  vector<int> topo = topologicalSort(k, adj);

  string ans = "";
  for (auto it : topo) {
    ans = ans + char(it + 'a');
  }

  return ans;
}
