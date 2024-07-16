#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int k = 0;
  int *i = &nums[0];
  int *j = &nums[1];
  int n = nums.size();

  for (; j < &nums[n]; ++j) {

    if (*i != *j) {
      *(++i) = *j;
      k++;
    }
  }

  cout << k + 1 << "\n";
  return 0;
}
