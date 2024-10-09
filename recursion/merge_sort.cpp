#include <bits/stdc++.h>
using namespace std;

void merge(int left, int right, int mid, vector<int> &arr) {
  int l = left, r = mid + 1;
  vector<int> temp;

  while (l <= left && r <= right) {
    if (arr[l] >= arr[r]) {
      temp.push_back(arr[r]);
      r++;
    } else {
      temp.push_back(arr[l]);
      l++;
    }
  }

  while (l <= mid) {
    temp.push_back(arr[l]);
    l++;
  }

  while (r <= right) {
    temp.push_back(arr[r]);
    r++;
  }

  while (left <= right) {
    arr[left] = temp[left];
    left++;
  }
}

void MerrgeSort(int left, int right, vector<int> &arr) {
  if (left >= right)
    return;
  int mid = left + (right - left) / 2;
  MerrgeSort(left, mid, arr);
  MerrgeSort(mid + 1, right, arr);
  merge(left, right, mid, arr);
}

int main() {
  vector<int> arr = {1, 2, 1};
  vector<int> ans;
  int n = arr.size();
  int k = 2;
  MerrgeSort(0, n - 1, arr);
  for (auto x : arr)
    cout << x << " ";
  cout << endl;
  return 0;
}
