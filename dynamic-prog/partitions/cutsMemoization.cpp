#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(int i, int j, vector<int>& cuts, vector<vector<int>>& dp)
    {
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        
        for(int index = i; index <= j; index++)
        {
            int cost = cuts[j+1] - cuts[i-1] + f(i, index-1, cuts, dp) + f(index+1, j, cuts, dp);

            mini = min(cost, mini);
        }

        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>> dp(n, vector<int> (n, -1));
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        return f(1, c, cuts, dp);
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