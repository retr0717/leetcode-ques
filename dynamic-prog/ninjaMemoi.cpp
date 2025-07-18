#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

int MaxMerit(int day, int last, vector<vector<int>> &activity, vector<vector<int>> &dp)
{
        int maxVal = 0;
        if(day == 0)
        {
                for(int i = 0 ; i < 3 ; i++)
                {
                        if(i != last)
                                maxVal = max(maxVal, activity[0][i]);
                }

                return maxVal;
        }

        if(dp[day][last] != -1) return dp[day][last];

        maxVal = 0;

        for(int i = 0 ; i < 3 ; i++)
        {
                if( i != last)
                {
                        int points = activity[day][i] + MaxMerit(day - 1, i, activity, dp);
                        maxVal = max(maxVal, points);
                }
        }

        return dp[day][last] = maxVal;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return MaxMerit(n-1, 3, points, dp);
}
