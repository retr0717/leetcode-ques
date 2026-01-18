#include <bits/stdc++.h>
using namespace std;

int longestBitonicSubsequence(vector<int>& arr, int n)
{
	vector<int> dp1(n+1, 1), dp2(n+1, 1);

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < i; j++)
        {
            if(arr[i] > arr[j] && 1+dp1[j] > dp1[i])
            {
                dp1[i] = 1 + dp1[j];
            }
        }
    }

    for(int i = n-1 ; i >= 0 ; i--)
    {
        for(int j = n-1 ; j > i ; j--)
        {
            if(arr[i] > arr[j] && 1+dp2[j] > dp2[i])
            {
                dp2[i] = 1+dp2[j];
            }
        }
    }

    //sum up two dp.
    //-1 is to decrement the common value when we iterate from both sides.
    int maxVal = 0;
    for(int i = 0 ; i < n ; i++)
    {
        maxVal = max(maxVal, dp1[i]+dp2[i]-1);
    }

    return maxVal;
}

int main() {
    vector<int> arr = {1, 11, 2, 10, 4, 5, 2, 1};
    int n = arr.size();
    cout << "Length of Longest Bitonic Subsequence: " << longestBitonicSubsequence(arr, n) << endl;
    return 0;
}