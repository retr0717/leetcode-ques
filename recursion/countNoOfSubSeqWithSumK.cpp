#include <bits/stdc++.h>
using namespace std;

int printfSubSequence(int index, vector<int> &arr, int sum, int n, int k) {

  if (sum > k)
    return 0;

  if (index == n) {
    if (sum == k)
      return 1;

    return 0;
  }

  sum += arr[index];

  int l = printfSubSequence(index + 1, arr, sum, n, k);

  sum -= arr[index];

  int r = printfSubSequence(index + 1, arr, sum, n, k);

  return l + r;
}

int main() {
  vector<int> arr = {1, 2, 1};
  vector<int> ans;
  int n = arr.size();
  int k = 2;
  cout << printfSubSequence(0, arr, 0, n, k) << endl;
  return 0;
}
