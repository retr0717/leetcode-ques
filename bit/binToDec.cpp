#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "1000";
    int ans = 0;
    int product = 1;

    for(int i = s.length()-1 ; i >= 0 ; i--)
    {
        if(s[i] == '1')
        {
            ans = ans + product;
        }

        product = product * 2;
    }

    cout<<ans<<endl;

    return 0;
}