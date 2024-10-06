#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> arr = {4, 3, 6, 2, 1, 1};
  int missing = 0, repeating = 0;

  sort(arr.begin(), arr.end());

  missing = arr[0];
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] != (missing + 1)) {
      missing = missing + 1;
    }
    if (arr[i] == arr[i - 1]) {
      repeating = arr[i];
    }

    missing = arr[i];
  }

  cout << "Missing: " << missing << endl;
  cout << "Repeating: " << repeating << endl;

  return 0;
}
