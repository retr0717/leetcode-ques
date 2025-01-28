#include <bits/stdc++.h>
using namespace std;

vector<int> MinimumCoins(int n) {
  vector<int> currency = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
  vector<int> coins;

  int coin = 0;
  int amount = n;

  while (amount != 0 && amount > 0) {
    if (currency[coin] <= amount) {
      amount -= currency[coin];
      coins.push_back(currency[coin]);
      continue;
    }

    coin++;
  }

  return coins;
}
