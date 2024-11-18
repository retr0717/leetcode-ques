#include <iostream>
#include <stdbool.h>
#include <vector>

using namespace std;

bool is_sorted(vector<int> &arr) {
  for (int i = 0; i < arr.size() - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      return false;
    }
  }
  return true;
}
int main() {
  vector<int> arr = {3, 4, 5, 1, 2};
  cout << "1st\n";
  int num = arr.back();
  arr.pop_back();
  arr.insert(arr.begin(), num);
  is_sorted(arr) ? cout << "Sorted\n" : cout << "Not sorted\n";
  cout << "2nd\n";
  cout << "1st\n";
  num = arr.back();
  arr.pop_back();
  arr.insert(arr.begin(), num);
  is_sorted(arr) ? cout << "Sorted\n" : cout << "Not sorted\n";

  int *elem = arr.begin();
  cout << "\n" << *elem << "\n";
  elem = arr.end();

  return 0;
}
