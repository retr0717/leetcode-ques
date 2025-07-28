#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        const int INF = 1e8;
        vector<int> prev(amount + 1, INF);

        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0)
                prev[j] = j / coins[0];
        }

        for (int i = 1; i < n; i++) {
            vector<int> temp(amount + 1, INF);
            for (int j = 0; j <= amount; j++) {
                int notTake = prev[j];
                int take = INF;
                if (j >= coins[i])
                    take = 1 + temp[j - coins[i]];

                temp[j] = min(take, notTake);
            }
            prev = temp;
        }

        return (prev[amount] >= INF) ? -1 : prev[amount];
    }
};

