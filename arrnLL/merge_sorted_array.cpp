#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void merge(vector<int> &arr1, int n, vector<int> &arr2, int m) {
    // Declare 2 pointers:
    int left = n;

    for (int i = 0; i < m; i++) {
      arr1[left++] = arr2[i];
    }

    sort(arr1.begin(), arr1.end());
  }
};

int main() {
  Solution sol;
  vector<int> nums1 = {1, 2, 3, 0, 0, 0}, nums2 = {2, 5, 6};
  int m = 3, n = 3;
  sol.merge(nums1, m, nums2, n);
}
