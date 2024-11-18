#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void Merge(vector<int> &nums, int low, int mid, int high) {
    vector<int> arr;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
      if (nums[left] <= nums[right]) {
        arr.push_back(nums[left]);
        left++;
      } else {
        arr.push_back(nums[right]);
        right++;
      }
    }

    while (left <= mid) {
      arr.push_back(nums[left]);
      left++;
    }

    while (right <= high) {
      arr.push_back(nums[right]);
      right++;
    }

    for (int i = low; i <= high; i++) {
      nums[i] = arr[i - low];
    }
  }

public:
  int CountPairs(vector<int> &nums, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++) {
      while (right <= high && nums[i] > 2LL * nums[right])
        right++;
      cnt += (right - (mid + 1));
    }

    return cnt;
  }

public:
  int MergeSort(vector<int> &nums, int low, int high) {
    int count = 0;
    if (low >= high)
      return count; // Corrected base condition
    int mid = (low + high) / 2;
    count += MergeSort(nums, low, mid);
    count += MergeSort(nums, mid + 1, high);
    count += CountPairs(nums, low, mid, high);
    Merge(nums, low, mid, high);
    return count;
  }

public:
  int reversePairs(vector<int> &nums) {
    int n = nums.size();
    return MergeSort(nums, 0, n - 1);
  }
};

int main() {
  vector<int> arr = {1, 3, 2, 3, 1};
  Solution sol;
  int pcount = sol.reversePairs(arr);
  return 0;
}
