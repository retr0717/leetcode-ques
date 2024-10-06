#include <bits/stdc++.h>
using namespace std;

void printNtoOne(int i, int n)
{
    if( i > n)
         return;
    printNtoOne(i+1, n);
    cout<<i<<endl;
}

int main()
{
    int n = 3;
    printNtoOne(1,3);
    return 0;
}