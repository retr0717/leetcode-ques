#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int findWays(int ind, int tar, vector<int>& coins)
    {
        if(ind == 0)    return (tar%coins[0] == 0);

        //notTake.
        int nTake = findWays(ind-1, tar, coins);
        int take = 0;
        //take if less than the target.
        if(coins[ind] <= tar) take = findWays(ind, tar-coins[ind], coins);

        return (nTake+take);
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        return findWays(n-1, amount, coins);
    }
};
