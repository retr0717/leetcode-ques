#include <iostream>
#include <vector>
using namespace std;

int findFloor(vector<int> &a, int n, int x) {
  int ans = -1, mid = 0, start = 0, end = a.size() - 1;
  while (start <= end) {
    mid = (start + end) / 2;
    if (a[mid] <= x) {
      ans = a[mid];
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  return ans;
}

int findCeil(vector<int> &a, int n, int x) {
  int ans = -1, mid = 0, start = 0, end = a.size() - 1;
  while (start <= end) {
    mid = (start + end) / 2;
    if (a[mid] >= x) {
      ans = a[mid];
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  return ans;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {

  int f = findCeil(a, n, x);
  int c = findFloor(a, n, x);
  return make_pair(c, f);
}

int main() {
  vector<int> a = {1, 2, 8, 10, 10, 12, 19};
  int n = a.size();
  int x = 5;
  pair<int, int> p = getFloorAndCeil(a, n, x);
  cout << p.first << " " << p.second << endl;
  return 0;
}
