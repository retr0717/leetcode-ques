#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<long> prev(amount+1, 0), curr(amount+1, 0);

        for(int tar = 0 ; tar <= amount ; tar++)
            prev[tar] = ( (tar%coins[0]) == 0);
        
        for(long ind = 1 ; ind < n ; ind++)
        {
            for(long tar = 0 ; tar <= amount ; tar++)
            {
                long nTake = prev[tar];
                int take = 0;
                if( coins[ind] <= tar ) take = curr[tar-coins[ind]];

                curr[tar] = (nTake+take);
            }

            prev = curr;
        }

        return prev[amount];
    }
};
