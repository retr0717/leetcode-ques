#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void Inversions(vector<int> &arr) {
    int n = arr.size();
    int c = 0;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (arr[j] < arr[i]) {
          c++;
        }
      }
    }

    cout << "\nTot Inversions : " << c << endl;
  }

public:
  int Merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int cnt = 0;

    while (left <= mid && right <= high) {
      if (arr[left] <= arr[right]) {
        temp.push_back(arr[left]);
        left++;
      } else {
        temp.push_back(arr[right]);
        right++;
        cnt += (mid - left + 1);
      }
    }

    while (left <= mid) {
      temp.push_back(arr[left]);
      left++;
    }

    while (right <= high) {
      temp.push_back(arr[right]);
      right++;
    }

    for (int i = low; i <= high; i++) {
      arr[i] = temp[i];
    }
    return cnt;
  }

public:
  int MergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high)
      return cnt;

    int mid = (low + high) / 2;

    cnt += MergeSort(arr, low, mid);
    cnt += MergeSort(arr, mid + 1, high);
    cnt += Merge(arr, low, mid, high);
    return cnt;
  }

public:
  int NoOfInversions(vector<int> &arr) {
    return MergeSort(arr, 0, arr.size() - 1);
  }
};

int main() {
  vector<int> arr = {1, 2, 3, 4, 5};
  vector<int> arr2 = {5, 4, 3, 2, 1};
  vector<int> arr3 = {5, 3, 2, 1, 4};

  Solution sol;
  sol.Inversions(arr);
  sol.Inversions(arr2);
  sol.Inversions(arr3);

  cout << "No of Inversions : " << sol.NoOfInversions(arr) << endl;
  cout << "No of Inversions : " << sol.NoOfInversions(arr2) << endl;
  cout << "No of Inversions : " << sol.NoOfInversions(arr3) << endl;

  return 0;
}
