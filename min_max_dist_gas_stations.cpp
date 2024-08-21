#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

// using priority queue

// double minimiseMaxDistance(vector<int> &arr, int k) {
//
//   vector<int> howMany(arr.size() - 1, 0);
//   priority_queue<pair<long double, int>> pq;
//
//   // set the initial section width and section no.
//   for (int i = 0; i < arr.size() - 1; i++) {
//     pq.push({(arr[i + 1] - arr[i]), i});
//   }
//
//   // adding new gas stations in btw the sections.
//   for (int i = 1; i <= k; i++) {
//     auto section = pq.top();
//     pq.pop();
//     int secIndex = section.second;
//     howMany[secIndex]++;
//     long double newSecLen = (arr[secIndex + 1] - arr[secIndex]) /
//                             ((long double)(howMany[secIndex] + 1));
//     pq.push({newSecLen, secIndex});
//   }
//
//   return pq.top().first;
// }

// optimal solution

int noOfGasStations(long double dist, vector<int> &arr) {
  int count = 0;
  for (int i = 1; i < arr.size(); i++) {
    int noInBtw = ((arr[i] - arr[i - 1]) / dist);
    if (((arr[i] - arr[i - 1]) / dist) == noInBtw * dist) {
      noInBtw--;
    }
    count += noInBtw;
  }

  return count;
}

double minimiseMaxDistance(vector<int> &arr, int k) {

  long double start = 0;
  long double end = 0;
  int n = arr.size();

  // find the end which is the highest diff dist among the gas stations.
  for (int i = 0; i < n - 1; i++) {
    end = max(end, (long double)arr[i + 1] - arr[i]);
  }

  long double diff = 1e-6;
  while (end - start > diff) {
    long double mid = (start + end) / (2.0);
    int count = noOfGasStations(mid, arr);
    if (count > k)
      start = mid;
    else
      end = mid;
  }

  return end;
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int k = 3;
  cout << minimiseMaxDistance(arr, k) << endl;
  return 0;
}
