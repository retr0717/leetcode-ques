#include <bits/stdc++.h>
using namespace std;

string kthPermutation(int n, int k) {

  int fact = 1;
  vector<int> nums;

  for (int i = 1; i < n; i++) {
    fact = fact * i;
    nums.push_back(i);
  }

  nums.push_back(n);
  k = k - 1;
  string str = "";

  while (true) {
    str = str + to_string(nums[k / fact]);
    nums.erase(nums.begin() + (k / fact));

    if (nums.size() == 0)
      break;

    k = k % fact;
    fact = fact / nums.size();
  }

  return str;
}

int main() {
  int n, k;
  cin >> n >> k;
  cout << kthPermutation(n, k) << endl;
  return 0;
}
