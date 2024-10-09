#include <bits/stdc++.h>
using namespace std;

bool printfSubSequence(int index, vector<int> &arr, vector<int> &ds, int sum,
                       int n, int k) {
  if (index == n) {
    if (sum == k) {
      for (auto x : ds)
        cout << x << " ";
      cout << endl;
      return true;
    }
    return false;
  }

  ds.push_back(arr[index]);
  sum += arr[index];

  if (printfSubSequence(index + 1, arr, ds, sum, n, k) == true)
    return true;

  sum -= arr[index];
  ds.pop_back();

  if (printfSubSequence(index + 1, arr, ds, sum, n, k) == true)
    return true;

  return false;
}

int main() {
  vector<int> arr = {1, 2, 1};
  vector<int> ans;
  int n = arr.size();
  int k = 2;
  vector<int> ds;
  printfSubSequence(0, arr, ans, 0, n, k);
  return 0;
}
