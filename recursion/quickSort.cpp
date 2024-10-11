
#include <bits/stdc++.h>
using namespace std;

int findPartitionIndex(vector<int>& arr, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = low;

    while( i < j )
    {
        while(arr[i] <= arr[pivot] && i <= high)
            i++;
        
        while(arr[j] > arr[pivot] && j >= low)
            j--;

        if( i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);

    return j;
}

void qs(vector<int>& arr, int low, int high)
{
    if(low < high)
    {
        int partitionIndex = findPartitionIndex(arr, low, high);
        qs(arr, low, partitionIndex-1);
        qs(arr, partitionIndex+1, high);
    }
}

vector<int> quickSort(vector<int>& arr)
{
    int low = 0;
    int high = arr.size()-1;

    qs(arr, low, high);

    return arr;
}


int main()
{
    vector<int> arr = {4,6,2,5,7,9,1,3};
    quickSort(arr);
    for(auto x : arr)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}