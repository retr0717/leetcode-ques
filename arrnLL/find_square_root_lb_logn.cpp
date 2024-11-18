#include <iostream>

int floor(int n) {
  int low = 1, high = n, ans = -1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (mid * mid <= n) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return ans;
}

int main() {
  int n = 28;
  std::cout << floor(n) << std::endl;
  return 0;
}
