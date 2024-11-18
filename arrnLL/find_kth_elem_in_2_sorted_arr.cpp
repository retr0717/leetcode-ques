#include <bits/stdc++.h>
#include <vector>
using namespace std;

int kthElement(vector<int> &arr1, vector<int> &arr2, int n, int m, int k) {
  // Write your code here
  int i = 0, j = 0;
  int len = (n + m);
  int count = 0;

  while (i < n && j < m) {
    if (arr1[i] < arr2[j]) {
      if (count == (k - 1))
        return arr1[i];
      i++;
      count++;
    } else {
      if (count == (k - 1))
        return arr2[j];
      j++;
      count++;
    }
  }

  while (i < n) {
    if (count == (k - 1))
      return arr1[i];
    i++;
    count++;
  }

  while (j < m) {
    if (count == (k - 1))
      return arr2[j];
    j++;
    count++;
  }

  return -1;
}

int main() {
  vector<int> arr1 = {2, 3, 4, 5};
  vector<int> arr2 = {7, 8};
  int result = kthElement(arr1, arr2, arr1.size(), arr2.size(), 4);
  return 0;
}
