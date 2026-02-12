#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);

        for(int ind = n-1; ind>= 0; ind--)
        {
            int maxVal = INT_MIN;
            int maxAns = INT_MIN;
            int len = 0;

            for(int j = ind; j < min(ind+k, n); j++)
            {
                len++;
                maxVal = max(arr[j], maxVal);
                int sum = maxVal*len + dp[j+1];
                maxAns = max(maxAns, sum);
            }

            dp[ind] = maxAns;
        }

        return dp[0];
    }
};

int main()
{
    vector<int> arr = {1,15,7,9,2,5,10};
    int k = 3;

    Solution obj;

    cout<<obj.maxSumAfterPartitioning(arr, k)<<endl;

    return 0;
}