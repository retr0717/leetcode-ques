#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long>> dp(n, vector<long> (amount+1, -1));

        for(int tar = 0 ; tar <= amount ; tar++)
            dp[0][tar] = ( (tar%coins[0]) == 0);
        
        for(long ind = 1 ; ind < n ; ind++)
        {
            for(long tar = 0 ; tar <= amount ; tar++)
            {
                long nTake = dp[ind-1][tar];
                int take = 0;
                if( coins[ind] <= tar ) take = dp[ind][tar-coins[ind]];

                dp[ind][tar] = (nTake+take);
            }
        }

        return dp[n-1][amount];
    }
};
