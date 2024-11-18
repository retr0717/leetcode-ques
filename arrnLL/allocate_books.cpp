#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int findStudentCount(vector<int> &arr, int pages) {
  long long pCount = 0;
  int studentCount = 1;
  for (int i = 0; i < arr.size(); i++) {
    if ((pCount + arr[i]) <= pages)
      pCount += arr[i];
    else {
      pCount = arr[i];
      studentCount++;
    }
  }

  cout << "pages: " << pages << " studentCount: " << studentCount << endl;

  return studentCount;
}

int findPages(vector<int> &arr, int n, int m) {

  if (m > n)
    return -1;

  int start = *max_element(arr.begin(), arr.end());
  int end = accumulate(arr.begin(), arr.end(), 0);

  cout << "start: " << start << " end: " << end << endl;

  while (start <= end) {
    int mid = (start + end) / 2;
    int studentCount = findStudentCount(arr, mid);
    if (studentCount > m)
      start = mid + 1;
    else
      end = mid - 1;
  }

  return start;
}

int main() {
  vector<int> arr = {1, 17, 14, 9, 15, 9, 14};
  int n = arr.size();
  int m = 7;
  cout << findPages(arr, n, m) << endl;
  return 0;
}
