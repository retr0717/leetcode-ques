#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool canWePlaceCows(vector<int> &stalls, int n, int cows, int dist) {
    int last = stalls[0];
    int cnt = 1;
    for (int i = 1; i < n; i++) {
      if (stalls[i] - last >= dist) {
        cnt++;
        last = stalls[i];
      }
    }
    return cnt >= cows;
  }

public:
  int aggressiveCows(vector<int> &stalls, int n, int cows) {
    sort(stalls.begin(), stalls.end());
    int start = 0, end = stalls[n - 1] - stalls[0];
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (canWePlaceCows(stalls, n, cows, mid)) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    return end;
  }
};

int main() {
  vector<int> stalls = {1, 2, 4, 8, 9};
  int n = stalls.size();
  int cows = 3;
  Solution obj;
  cout << obj.aggressiveCows(stalls, n, cows) << endl;
  return 0;
}
