#include <bits/stdc++.h>
using namespace std;

int findMaxFruits(vector<int> &arr, int n) {
  int l, r, maxLen;
  l = r = maxLen = 0;
  map<int, int> mpp;
  int k = 2;

  while (r < n) {
    mpp[arr[r]]++;

    if (mpp.size() > k) {
      mpp[arr[l]]--;
      if (mpp[arr[l]] == 0)
        mpp.erase(arr[l]);
      l++;
    }

    if (mpp.size() <= k)
      maxLen = max(maxLen, r - l + 1);
    r++;
  }

  return maxLen;
}
