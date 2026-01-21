#include <bits/stdc++.h>
using namespace std;

int partitions(int i , int j, vector<int> &arr)
{
    if(i == j ) return 0;

    int mini = 1e9;

    //get all partitions.
    for(int k = i ; k < j ; k++)
    {
        int steps = partitions(i , k , arr) + partitions(k + 1 , j , arr) + arr[i - 1] * arr[k] * arr[j];
        //minimize the steps.

        if(steps < mini)
            mini = steps;
    }
    return mini;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 30};
    int n = arr.size();

    cout << "Minimum number of multiplications is " << partitions(1, n - 1, arr) << endl;

    return 0;
}