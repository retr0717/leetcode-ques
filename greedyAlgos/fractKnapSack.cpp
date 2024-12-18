#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> &item1, pair<int, int> &item2) {
  if (((double)item1.second / (double)item1.first) >=
      ((double)item2.second / (double)item2.first))
    return true;
  return false;
}

double maximumValue(vector<pair<int, int>> &items, int n, int w) {
  sort(items.begin(), items.end(), comparator);

  int weight = w;
  double totValue = 0.0;

  for (int i = 0; i < n; i++) {
    if (items[i].first <= weight) {
      totValue += items[i].second;
      weight -= items[i].first;
    } else {
      totValue += ((double)items[i].second / (double)items[i].first) * weight;
      break;
    }
  }

  return totValue;
}
