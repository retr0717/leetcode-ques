#include <bits/stdc++.h> 
using namespace std;

int frogJump(int n, vector<int> &heights)
{
    int prev = 0, prev2 = 0;

    for(int i = 1; i < n; i++)
    {
        int fs = prev + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        if(i > 1) ss = prev2 + abs(heights[i] - heights[i-2]);

        int curr = min(fs, ss);

        prev2 = prev;
        prev = curr;
    }

    return prev;
}
