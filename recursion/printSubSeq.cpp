#include <bits/stdc++.h>
using namespace std;

void print(vector<int>& result)
{
    if(result.size() == 0)
    {
        cout<<"{}"<<endl;
        return;
    }   

    for(int x : result)
        cout<<x<<" ";
    cout<<endl;
}

void subSeq(vector<int>& arr, int index, vector<int>& result, int n)
{
    if(index == n)
    {
        print(result);
        return;
    }

    //take.
    result.push_back(arr[index]);
    subSeq(arr,index+1, result, n);
    
    //not take.
    result.pop_back();
    subSeq(arr, index+1, result, n);
}

int main()
{
    vector<int> arr = {3,1,2};
    vector<int> result;
    subSeq(arr, 0, result, arr.size());
    return 0;
}