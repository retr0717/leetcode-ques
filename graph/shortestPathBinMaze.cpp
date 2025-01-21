//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
private:
  bool boundaryCheck(int row, int col, int rowLimit, int colLimit) {
    return (row >= 0 && row < rowLimit && col >= 0 && col < colLimit);
  }

public:
  int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                   pair<int, int> destination) {
    int n = grid.size();
    int m = grid[0].size();

    // If source and destination are the same no movement is needed.
    if (source == destination) {
      return 0;
    }

    queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> dist(n, vector<int>(m, 1e9)); // Distance matrix

    dist[source.first][source.second] = 0;
    q.push({0, {source.first, source.second}});

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while (!q.empty()) {
      auto it = q.front();
      q.pop();

      int dis = it.first;
      int r = it.second.first;
      int c = it.second.second;

      // Explore the 4 possible directions
      for (int i = 0; i < 4; i++) {
        int newRow = r + dr[i];
        int newCol = c + dc[i];

        if (boundaryCheck(newRow, newCol, n, m) && grid[newRow][newCol] == 1 &&
            dis + 1 < dist[newRow][newCol]) {
          dist[newRow][newCol] = dis + 1;
          q.push({dis + 1, {newRow, newCol}});

          // If we reach the destination, return the distance
          if (newRow == destination.first && newCol == destination.second) {
            return dis + 1;
          }
        }
      }
    }

    return -1; // Return -1 if there is no valid path
  }
};

//{ Driver Code Starts.
int main() {

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
      }
    }

    pair<int, int> source, destination;
    cin >> source.first >> source.second;
    cin >> destination.first >> destination.second;
    Solution obj;
    cout << obj.shortestPath(grid, source, destination) << endl;

    cout << "~" << "\n";
  }
}

// } Driver Code Ends
