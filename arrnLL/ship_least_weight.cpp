#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int sum(vector<int> &weights) {
    int s = 0;
    for (int load : weights)
      s += load;
    return s;
  }

public:
  int findDays(vector<int> weights, int capacity) {
    int load = 0, days = 1;
    for (int i = 0; i < weights.size(); i++) {
      if (load + weights[i] > capacity) {
        days += 1;
        load = weights[i];
      } else
        load += weights[i];
    }

    return days;
  }

public:
  int shipWithinDays(vector<int> &weights, int days) {

    auto maxIt = max_element(weights.begin(), weights.end());
    int start = *maxIt;
    int end = sum(weights);
    int ans = 0;

    while (start <= end) {
      int mid = (start + end) / 2;
      int nod = findDays(weights, mid);
      if (nod <= days) {
        ans = mid;
        end = mid - 1;
      } else
        start = mid + 1;
    }

    return ans;
  }
};

int main() {
  Solution s;
  vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int days = 5;
  cout << s.shipWithinDays(weights, days) << endl;
  return 0;
}
