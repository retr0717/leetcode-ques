#include <bits/stdc++.h>
using namespace std;

//counting the no of set one's in each position.
//if the count is not a multiple of three then that is the single number.

void solution1()
{
     int arr[] = {2,2,2,1,4,4,4,3,3,3};
    int ans = 0;

    for(int bitIndexNum = 0 ; bitIndexNum < 32 ; bitIndexNum++)
    {
        int count = 0;
        for(int i = 0 ; i < ((sizeof(arr))/sizeof(arr[0])) ; i++)
        {

            if(arr[i] &  (1 << bitIndexNum))
                count++;
        }
        
        if(count % 3 == 1)
            ans = ans | (1 << bitIndexNum);

    }

    cout<<ans<<endl;
}


//checking every element which is 3 index away and checking if the previous value is same or not
//if not that is the single num.
void solution2()
{
    vector<int> arr = {2,2,2,1,4,4,4,3,3,3};
    sort(arr.begin(), arr.end());

    for(int i = 1 ; i < arr.size(); i+=3)
    {
        if(arr[i] != arr[i-1])
        {
            cout<<arr[i-1]<<endl;
            return;
        }
    }

    cout<<arr[arr.size() - 1]<<endl;
}

int main()
{
    //solution1();
    //solution2();
    vector<int> arr = {2,2,2,1,4,4,4,3,3,3};
    int ones = 0;
    int twos = 0;

    for(int i = 0 ; i < arr.size() ; i++)
    {
        ones = (ones ^ arr[i]) & ~twos;
        twos = (twos ^ arr[i]) & ~ones;
    }

    cout<<ones<<endl;

    return 0;
}