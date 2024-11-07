#include <bits/stdc++.h>
using namespace std;

int xorSum(int n) {
  if (n % 4 == 1)
    return 1;
  else if (n % 4 == 2)
    return n + 1;
  else if (n % 4 == 3)
    return 0;
  else
    return n;

  return -1;
}

int main() {
  int n;
  cout << "Enter the no : ";
  cin >> n;

  int result = xorSum(n);
  cout << result << endl;

  return 0;
}
