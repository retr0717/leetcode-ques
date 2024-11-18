#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> arr = {1, 2, 3, 4, 5};
  int k = 2;
  int n = arr.size();
  k = k % n;
  if (k > n)
    return 0;
  reverse(arr.begin(), arr.end());
  reverse(arr.begin(), arr.begin() + k);
  reverse(arr.begin() + k, arr.end());

  for (auto i = arr.begin(); i != arr.end(); i++) {
    cout << *i << "  ";
  }
  cout << "\n";
  return 0;
}
