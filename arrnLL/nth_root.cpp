#include <iostream>
using namespace std;

int power(int mid, int n, int m) {
  long long ans = 1;
  for (int i = 1; i <= n; i++) {
    ans *= mid;
    if (ans > m)
      return 2;
  }

  if (ans == m)
    return 1;
  return 0;
}

int NthRoot(int n, int m) {
  int low = 1, high = n;

  while (low <= high) {
    int mid = (low + high) / 2;
    int p = power(mid, n, m);
    if (p == 1) {
      return mid;
    } else if (p == 0) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1;
}

int main() {
  int n = 10;
  int m = 1024;
  cout << NthRoot(n, m) << endl;
  return 0;
}
