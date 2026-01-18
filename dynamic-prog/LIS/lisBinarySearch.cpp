#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;

    for(int i = 1 ; i < n; i++)
    {
        if(temp.back() < arr[i])
        {
            temp.push_back(arr[i]);
            len++;
        }
        else
        {
            //perform binary search.
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }

    return len;
}
int main() {
    int arr[] = {10,9,2,5,3,7,101,18};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Length of Longest Increasing Subsequence: " << longestIncreasingSubsequence(arr, n) << endl;
    return 0;
}