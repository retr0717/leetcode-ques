#include <iostream>
#include <vector>
using namespace std;

double median(vector<int> &a, vector<int> &b) {
  // Write your code here.
  int n = a.size();
  int m = b.size();
  int len = (n + m);
  int sMid = len / 2;
  int fMid = sMid - 1;
  int count = 0;
  int mid2 = -1, mid1 = -1;
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (a[i] < b[j]) {
      if (count == fMid)
        mid1 = a[i];
      if (count == sMid)
        mid2 = a[i];
      count++;
      i++;
    } else {
      if (count == fMid)
        mid1 = b[j];
      if (count == sMid)
        mid2 = b[j];
      count++;
      j++;
    }
  }

  while (i < n) {
    if (count == fMid)
      mid1 = a[i];
    if (count == sMid)
      mid2 = a[i];
    count++;
    i++;
  }

  while (j < m) {
    if (count == fMid)
      mid1 = b[j];
    if (count == sMid)
      mid2 = b[j];
    count++;
    j++;
  }

  if (len % 2 == 1)
    return mid2;

  return (double)((double)(mid1 + mid2)) / (2.0);
}

int main() {
  vector<int> a = {2, 4, 6};
  vector<int> b = {1, 3};
  double result = median(a, b);
  return 0;
}
