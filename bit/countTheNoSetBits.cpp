#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 16;
    int count = 0;

    while(n > 1)
    {
        count += (n&1);
        n = n >> 1;
    }

    cout<<"No Of Set Bits : "<<++count<<endl;
    return 0;
}