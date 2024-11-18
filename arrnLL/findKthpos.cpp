#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool exists(vector<int> &arr, int num) {
    int start = 0, end = arr.size() - 1;
    while (start <= end) {
      int mid = (start + end) / 2;
      if (arr[mid] == num)
        return true;
      else if (num > arr[mid])
        start = mid + 1;
      else
        end = mid - 1;
    }

    return false;
  }

public:
  int findKthPositive(vector<int> &arr, int k) {
    vector<int> missing;
    int num = 1;

    while (missing.size() <= k) {
      if (!exists(arr, num))
        missing.push_back(num);

      num += 1;
    }

    return missing[k - 1];
  }
};

int main() {
  vector<int> arr = {2, 3, 4, 7, 11};
  int k = 5;
  Solution obj;
  cout << obj.findKthPositive(arr, k) << endl;
