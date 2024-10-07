#include <bits/stdc++.h>
using namespace std;

void reverseTwoPointer(int l, int r, vector<int>& arr)
{
    if(l >= r)
        return;
    swap(arr[l], arr[r]);
    reverseTwoPointer(l+1, r-1, arr);
}

void reverseSinglePointer(int i, int n, vector<int>& arr)
{
    if(i >= n/2)
        return;
    swap(arr[i], arr[n-i-1]);
    reverseSinglePointer(i+1, n, arr);
}

int main()
{
    vector<int> arr = {3,2,1,5,4};
    //reverseTwoPointer(0,arr.size()-1, arr);
    reverseSinglePointer(0, arr.size(), arr);
    for(int x : arr)
        cout<<x<<" "<<endl;
    
    return 0;
}