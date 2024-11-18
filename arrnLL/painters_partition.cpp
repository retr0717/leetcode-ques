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

int findLargestMinDistance(vector<int> &boards, int k) {

  if (k > boards.size())
    return -1;
  int start = *max_element(boards.begin(), boards.end());
  int end = accumulate(boards.begin(), boards.end(), 0);

  while (start <= end) {
    int mid = (start + end) / 2;
    int boardCount = divisions(boards, k, mid);
    if (boardCount > k) {
      start = mid + 1;
    } else
      end = mid - 1;
  }

  return start;
}

int main() {
  vector<int> boards = {10, 20, 30, 40};
  int k = 2;
  int minSum = findLargestMinDistance(boards, k);
  cout << minSum << endl;
  return 0;
}
