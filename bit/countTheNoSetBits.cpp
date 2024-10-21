#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 16;
    int count = 0;

    if( n == 0)
        goto zero;
    while(n != 1)
    {
        if(n % 2 != 0)
            count++;
        n = n / 2;
    }

    cout<<"No Of Set Bits : "<<++count<<endl;
    goto stop;
    zero:
        cout<<"No Of Set Bits : "<<count<<endl;
        goto stop;
    one:
        cout<<"No Of Set Bits : "<<++count<<endl;
    stop:
        return 0;
}