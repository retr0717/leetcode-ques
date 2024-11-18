#include <iostream>
#include <vector>

using namespace std;

int main() {
  std::vector<int> nums = {2, 3, 5, 1, 9};
  int k = 10;
  int n = nums.size();
  int preCount = 0;

  int count = 0;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {

      sum += nums[j];
      if (sum == k) {
        count = max(count, j - i + 1);
      }

      cout << "Sum :" << sum << "\n";
      cout << "Count : " << count << "\n";
    }
  }
  cout << "\nCount : " << count << "\n";
  return 0;
}
