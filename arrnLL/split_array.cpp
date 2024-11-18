#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int divisions(vector<int> &arr, int k, int sum) {
  long long div = 0;
  int divCount = 1;

  for (int i = 0; i < arr.size(); i++) {
    if (div + arr[i] <= sum) {
      div += arr[i];
    } else {
      divCount++;
      div = arr[i];
    }
  }

  return divCount;
}
int splitArray(vector<int> &arr, int k) {

  if (k > arr.size())
    return -1;
  int start = *max_element(arr.begin(), arr.end());
  int end = accumulate(arr.begin(), arr.end(), 0);

  while (start <= end) {
    int mid = (start + end) / 2;
    int divCount = divisions(arr, k, mid);
    if (divCount > k) {
      start = mid + 1;
    } else
      end = mid - 1;
  }

  return start;
}

int main() {
  vector<int> arr = {7, 2, 5, 10, 8};
  int k = 2;
  cout << splitArray(arr, k) << endl;
  return 0;
}
