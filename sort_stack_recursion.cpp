#include <bits/stdc++.h>
using namespace std;

void sort_stack(vector<int> &v, int start, int end) {
  if (start == end)
    return;

  sort_stack(v, start + 1, end);
  int temp = v[start];
  int i = start + 1;
  while (i < end && v[i] < temp) {
    v[i - 1] = v[i];
    i++;
  }
  v[i - 1] = temp sort_stack(v, start + 1, end);
}

int main() {
  vector<int> v = {5, 1, 2, 3, 4};
  sort_stack(v, 0, v.size());
  for (auto x : v)
    cout << x << " ";

  return 0;
}
