#include <bits/stdc++.h>
using namespace std;

void printNtoOne(int i, int n)
{
    if(i < 1)
        return;
    printNtoOne(i-1, n);
    cout<<i<<endl;
}

int main()
{
    int n = 3;
    printNtoOne(n,n);
    return 0;
}