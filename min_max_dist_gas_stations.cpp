#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

double minimiseMaxDistance(vector<int> &arr, int k) {

  vector<int> howMany(arr.size() - 1, 0);
  priority_queue<pair<long double, int>> pq;

  // set the initial section width and section no.
  for (int i = 0; i < arr.size() - 1; i++) {
    pq.push({(arr[i + 1] - arr[i]), i});
  }

  // adding new gas stations in btw the sections.
  for (int i = 1; i <= k; i++) {
    auto section = pq.top();
    pq.pop();
    int secIndex = section.second;
    howMany[secIndex]++;
    long double newSecLen = (arr[secIndex + 1] - arr[secIndex]) /
                            ((long double)(howMany[secIndex] + 1));
    pq.push({newSecLen, secIndex});
  }

  return pq.top().first;
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int k = 3;
  cout << minimiseMaxDistance(arr, k) << endl;
  return 0;
}
