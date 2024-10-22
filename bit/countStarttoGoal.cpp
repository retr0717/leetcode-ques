#include <bits/stdc++.h>
using namespace std;

int main()
{
    int start = 10;
    int goal = 7;
    int count = 0;

    int n = start ^ goal;

    for(int i = 0 ; i < 32 ; i++)
    {
        if(n & (1 << i))
            count+=1;
    }

    cout<<count<<endl;
}