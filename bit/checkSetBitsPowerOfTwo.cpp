#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 13;
    if((n & (n-1)) != 0)
        cout<<"Even Set bits";
    else
        cout<<"Odd Set Bits"<<endl;
    return 0;
}