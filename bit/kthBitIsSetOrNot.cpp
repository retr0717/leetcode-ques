#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 13, k = 2;

    //using right shift operator.
    if(((n >> k) & 1) != 0)
    {
        cout<<"set"<<endl;
        return 0;
    }
    cout<<"Not Set"<<endl;

    //using left shift operator.
    if(((1 << k) & n) != 0)
    {
        cout<<"set"<<endl;
        return 0;
    }
    cout<<"Not Set"<<endl;
    return 0;
}