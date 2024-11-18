#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findLast(vector<int> &a, int n, int x) {
    int start = 0, end = n - 1, ans = -1;
    while (start <= end) {
      int mid = (start + end) / 2;
      if (a[mid] == x) {
        ans = mid;
        start = mid + 1;
      } else if (x < a[mid]) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }

    return ans;
  }

public:
  int findFirst(vector<int> &a, int n, int x) {
    int start = 0, end = n - 1, ans = -1;
    while (start <= end) {
      int mid = (start + end) / 2;
      if (a[mid] == x) {
        ans = mid;
        end = mid - 1;
      } else if (x > a[mid]) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }

    return ans;
  }

public:
  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> pair = {-1, -1};

    pair[0] = findFirst(nums, nums.size(), target);
    pair[1] = findLast(nums, nums.size(), target);

    return pair;
  }
};

int main() {
  Solution obj;
  vector<int> arr = {5, 7, 7, 8, 8, 10};
  vector<int> ans = obj.searchRange(arr, 8);
  cout << ans[0] << " " << ans[1] << endl;
  return 0;
}

/*
loop through
find the first occurence
for(int i = 0 ; i < n ; i++)
{
    if(arr[i] == target && vector[0] != -1)
    {
        vector[0] = i;
    }
    else if(arr[i] == target){
        vector[i] = i;
    }
}
*/
