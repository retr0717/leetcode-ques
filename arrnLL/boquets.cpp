#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool possible(vector<int> &bloomDay, int day, int k, int m) {
    long long nob = 0, c = 0;
    for (long long i = 0; i < bloomDay.size(); i++) {
      if (bloomDay[i] <= day)
        c++;
      else {
        nob += (c / k);
        c = 0;
      }
    }

    nob += (c / k);

    return nob >= m;
  }

public:
  int minDays(vector<int> &bloomDay, int m, int k) {

    auto minIt = min_element(bloomDay.begin(), bloomDay.end());
    long long min = *minIt;
    auto maxIt = max_element(bloomDay.begin(), bloomDay.end());
    long long max = *maxIt;
    long long ans = -1;
    while (min <= max) {
      long long mid = (min + max) / 2;
      if (possible(bloomDay, mid, k, m)) {
        ans = mid;
        max = mid - 1;
      } else {
        min = mid + 1;
      }
    }

    return ans;
  }
};

int main() {
  Solution s;
  vector<int> bloomDay = {1, 10, 3, 10, 2};
  cout << s.minDays(bloomDay, 3, 1) << endl;
  return 0;
}
