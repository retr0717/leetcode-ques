#include <iostream>

using namespace std;

class Solution {
public:
  int findLast(int arr[], int n, int x) {
    int start = 0, end = n - 1, ans = -1;
    while (start <= end) {
      int mid = (start + end) / 2;
      if (arr[mid] == x) {
        ans = mid;
        start = mid + 1;
      } else if (arr[mid] < x) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }

    return ans;
  }

public:
  int findFirst(int arr[], int n, int x) {
    int start = 0, end = n - 1, ans = -1;
    while (start <= end) {
      int mid = (start + end) / 2;
      if (arr[mid] == x) {
        ans = mid;
        end = mid - 1;
      } else if (x > arr[mid]) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }

    return ans;
  }

public:
  /* if x is present in arr[] then returns the count
          of occurrences of x, otherwise returns 0. */
  int count(int arr[], int n, int x) {
    int fc = findFirst(arr, n, x);
    int lc = findLast(arr, n, x);
    int count = lc - fc + 1;

    return count;
  }
};
