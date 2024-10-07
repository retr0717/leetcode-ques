#include <bits/stdc++.h>
using namespace std;

bool palindrome(int i, int n, string str)
{
    if(i >= n/2)
        return true;
    if(str[i] != str[n-i-1])
        return false;
    
    return palindrome(i+1, n, str);
}

int main()
{
    string str = "madam";
    string str2 = "madsm";
    bool result = palindrome(0, str.length(), str);
    bool result2 = palindrome(0, str2.length(), str2);

    cout<<"Result 1 : "<<result<<endl;
    cout<<"Result 2 : "<<result2<<endl;

    return 0;
}