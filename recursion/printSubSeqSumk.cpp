#include <bits/stdc++.h>
using namespace std;

void printfSubSequence(int index, vector<int> &arr, vector<int> &ds, int sum,
                       int n, int k) {
  if (index == n) {
    if (sum == k) {
      for (auto x : ds)
        cout << x << " ";
      cout << endl;
    }
    return;
  }

  ds.push_back(arr[index]);
  sum += arr[index];
  printfSubSequence(index + 1, arr, ds, sum, n, k);
  sum -= arr[index];
  ds.pop_back();
  printfSubSequence(index + 1, arr, ds, sum, n, k);
}

int main() {
  vector<int> arr = {1, 2, 3};
  vector<int> ans;
  int n = arr.size();
  int k = 2;
  vector<int> ds;
  printfSubSequence(0, arr, ans, 0, n, k);
  return 0;
}
