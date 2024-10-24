#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {4, 1, 2, 1, 2};
    int sum = 0;
    for(int i = 0 ; i < ((sizeof(arr))/sizeof(arr[0])) ; i++)
    {
        sum ^= arr[i];
    }

    cout<<sum<<endl;

    return 0;
}