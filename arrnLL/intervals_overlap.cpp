#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    int n = intervals.size();
    vector<vector<int>> ans;
    int k = 0;

    sort(intervals.begin(), intervals.end());

    for (int i = 0; i < n; i++) {
      if (ans.empty() || intervals[i][0] > ans.back()[1]) {
        ans.push_back(intervals[i]);
      } else {
        ans.back()[1] = max(ans.back()[1], intervals[i][1]);
      }
    }

    return ans;
  }
};

int main() {
  Solution s;
  vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  vector<vector<int>> ans = s.merge(intervals);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i][0] << " " << ans[i][1] << endl;
  }
  return 0;
}
