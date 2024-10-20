#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 9;

    string s = "";

    while(n != 1)
    {
        if(n % 2 == 0)
            s = s + "0";
        else
            s = s + "1";
        
        n = n / 2;
    }

    s = s + "1";

    reverse(s.begin(), s.end());
    cout<<s<<endl;
}