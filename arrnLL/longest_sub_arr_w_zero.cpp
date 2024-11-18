#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int LongestSub(vector<int> &A) {

    unordered_map<int, int> mpp;
    int maxi = 0;
    int sum = 0;
    for (int i = 0; i < A.size(); i++) {
      sum += A[i];
      if (sum == 0) {
        maxi = i + 1;
      } else {
        if (mpp.find(sum) != mpp.end()) {
          maxi = max(maxi, i - mpp[sum]);
        } else {
          mpp[sum] = i;
        }
      }
    }

    return maxi;
  }
};

int main() {
  vector<int> nums = {9, -3, 3, -1, 6 - 5};
  Solution s;
  int count = s.LongestSub(nums);
  cout << "Count: " << count << endl;
  return 0;
}
