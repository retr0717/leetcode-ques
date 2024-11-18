#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findMax(vector<int> &piles, int n) {
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
      maxi = max(maxi, piles[i]);
    }
    return maxi;
  }

public:
  long long TotalHours(vector<int> &piles, int eatCount) {
    long long hours = 0;
    for (int i = 0; i < piles.size(); i++) {
      // Adding eatCount - 1 ensures that the division rounds up (ceiling)
      hours += (piles[i] + eatCount - 1) / eatCount;
    }
    return hours;
  }

public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int low = 1;
    int high = findMax(piles, piles.size());

    while (low <= high) {
      int mid = low + (high - low) / 2;
      long long totHours =
          TotalHours(piles, mid); // Use long long to avoid overflow
      if (totHours <= h) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return low;
  }
};

int main() {
  Solution sol;
  vector<int> piles = {3, 6, 7, 11};
  int h = 8;
  cout << sol.minEatingSpeed(piles, h) << endl;
  return 0;
}
