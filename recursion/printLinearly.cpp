#include <bits/stdc++.h>
using namespace std;

void printLinearly(int n, int i)
{
    if(i > n)
        return;
    cout<<i<<endl;
    printLinearly(n,i+1);
}

int main()
{
    int n = 6;
    printLinearly(6,1);
}