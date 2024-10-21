#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 13;
    int k = 1;

    n = n & (~(1 << k));

    cout<<n<<endl;
    return 0;
}