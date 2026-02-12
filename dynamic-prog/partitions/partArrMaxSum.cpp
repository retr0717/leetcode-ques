#include    <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(int ind, int n, vector<int>& arr, int k)
    {
        if(ind == n) return 0;

        int maxVal = INT_MIN;
        int maxAns = INT_MIN;
        int len = 0;

        for(int j = ind; j < min(ind+k, n); j++)
        {
            len++;
            maxVal = max(arr[j], maxVal);
            int sum = maxVal*len + f(j+1, n, arr, k);
            maxAns = max(maxAns, sum);
        }

        return maxAns;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        return f(0, n, arr, k);
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