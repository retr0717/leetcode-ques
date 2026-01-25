#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        
        int c = cuts.size();
        vector<vector<int>> dp(c+2, vector<int> (c+2, 0));
        
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        for(int i = c; i >=1 ; i--)
        {
            for(int j = 1; j <= c; j++)
            {
                if(i > j) continue;

                int mini = INT_MAX;
                for(int k = i; k <= j; k++)
                {
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];

                    mini = min(mini, cost);
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][c];
    }
};

int main()
{
    int n = 7;
    vector<int> cuts = {1, 3, 4, 5};

    Solution obj;
    cout << "Minimum cost to cut the stick is " << obj.minCost(n, cuts) << endl;

    return 0;
}