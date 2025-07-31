#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<int> prev(w+1, 0), curr(w+1, 0);

    for(int val = 0 ; val <= w ; val++)
    {
        if (val >= weight[0])
            prev[val] = (val / weight[0]) * profit[0];
        else
            prev[val] = 0;
    }
    
    for(int index = 1 ; index < n ; index++)
    {
        for(int val = 0 ; val <= w ; val++)
        {
            int nTake = prev[val];
            int take = INT_MIN;
            if(weight[index] <= val) 
                take = profit[index] + curr[val-weight[index]];

            curr[val] = max(nTake, take);
        }

        prev = curr;
    }

    return prev[w];
}
