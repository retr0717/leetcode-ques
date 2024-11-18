#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int dSum(vector<int> &nums, int divisor) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += ceil((double)nums[i] / (double)divisor);
    }

    return sum;
  }

public:
  int smallestDivisor(vector<int> &nums, int threshold) {
    auto maxIt = max_element(nums.begin(), nums.end());
    int min = 1;
    int max = *maxIt;
    int divisor = 0;

    while (min <= max) {
      int mid = (min + max) / 2;
      int sum = dSum(nums, mid);
      if (sum <= threshold) {
        divisor = mid;
        max = mid - 1;
      } else
        min = mid + 1;
    }

    return divisor;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 2, 5, 9};
  int threshold = 6;
  cout << s.smallestDivisor(nums, threshold) << endl;
  return 0;
}
