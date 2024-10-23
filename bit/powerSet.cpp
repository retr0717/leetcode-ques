#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 3;
    int arr[] = {1,2,3};
    int size = sizeof(arr)/arr[0];
    
    int subsets = 1 << n;

    for(int num = 0 ; num < subsets ; num++)
    {
        for(int i = 0 ; i < size ; i++)
        {
            if( num & (1 << i))
                cout<<arr[i];
        }
        cout<<endl;
    }

    return 0;
}