#include <bits/stdc++.h>
using namespace std;

void sumOfN(int i, int sum)
{
    if(i < 1)
    {
        cout<<sum<<endl;
        return;
    }

    sumOfN(i-1, sum+i);
}

int main()
{
    int n = 4;
    sumOfN(n, 0);
    return 0;
}