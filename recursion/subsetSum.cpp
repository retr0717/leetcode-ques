#include <bits/stdc++.h>
using namespace std;

int sumOfArr(vector<int>& arr)
{
	int sum = 0;
	for(auto x : arr)
		sum += x;
	return sum;
}

void subSeq(vector<int>& arr, vector<int>& ans, int index, int n, int sum)
{
    if(index == n)
    {
		ans.push_back(sum);
        return;
    }

    //take.
    subSeq(arr,ans,index+1, n, sum + arr[index]);
    
    //not take.
    subSeq(arr, ans, index+1, n, sum);
}

int main()
{
    vector<int> arr = {5,2,1};
    vector<int> ans;
    subSeq(arr, ans, 0, arr.size(), 0);
    sort(ans.begin(), ans.end());

    for(auto x : ans)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}