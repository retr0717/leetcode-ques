#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void Merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;
    while (low <= mid && right <= high) {
      if (arr[left] <= arr[right]) {
        temp.push_back(arr[left]);
        left++;
      } else {
        temp.push_back(arr[right]);
        right++;
      }
    }

    // remaining elements in left half.
    while (left <= mid) {
      temp.push_back(arr[left]);
      left++;
    }

    // remaining elements in right half.
    while (right <= high) {
      temp.push_back(arr[right]);
      right++;
    }

    // copy from temp to arr.
    for (int i = low; i <= high; i++) {
      arr[i] = temp[i - low];
    }
  }

public:
  void MergeSort(vector<int> &arr, int low, int high) {
    if (low >= high)
      return;
    int mid = (low + high) / 2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);
    Merge(arr, low, mid, high);
  }
};

int main() {
  vector<int> arr = {12, 11, 13, 5, 6, 7};
  Solution s;
  s.MergeSort(arr, 0, arr.size() - 1);
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
