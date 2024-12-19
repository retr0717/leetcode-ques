#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    vector<vector<int>> result;
    int i = 0;
    int n = intervals.size();
    vector<int> nIntervalCpy = newInterval;

    while (i < n && intervals[i][1] < nIntervalCpy[0]) {
      result.push_back(intervals[i]);
      i++;
    }

    while (i < n && intervals[i][0] <= nIntervalCpy[1]) {
      nIntervalCpy[0] = min(intervals[i][0], nIntervalCpy[0]);
      nIntervalCpy[1] = max(intervals[i][1], nIntervalCpy[1]);
      i++;
    }

    result.push_back(nIntervalCpy);

    while (i < n) {
      result.push_back(intervals[i]);
      i++;
    }

    return result;
  }
};
