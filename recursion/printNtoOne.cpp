#include <bits/stdc++.h>
using namespace std;

void printNtoOne(int n)
{
    if( n == 0)
        return;
    cout<<n<<endl;
    printNtoOne(n-1);
}

int main()
{
    int n = 10;
    printNtoOne(n);
    return 0;
}