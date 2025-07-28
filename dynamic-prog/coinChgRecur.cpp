#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int MinCoins(int index, int tar, vector<int> &coins)
    {
        if(index == 0)
        {
            if( (tar%coins[index]) == 0) return (tar/coins[index]);
            else return 1e8;
        }

        int nTake = MinCoins(index-1, tar, coins);
        int take = 1e8;
        if(tar >= coins[index])
            take = 1 + MinCoins(index, tar-coins[index], coins);
        
        return min(take, nTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        if(amount == 0) return 0;
        if(n == 1) return -1;

        return MinCoins(n-1, amount, coins);
    }
};
