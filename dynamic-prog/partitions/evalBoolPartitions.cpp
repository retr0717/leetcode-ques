#include <bits/stdc++.h>
#define ll long long
using namespace std;

int mod = 1000000007;

class Solution {
private:
    ll f(int i, int j, int isTrue, string exp)
    {
        if(i > j) return 0;

        if(i == j){
            if(isTrue) return exp[i] == 't';
            else return exp[i] == 'f';
        }

        ll ways = 0;

        for(int ind = i+1; ind <= j-1; ind = ind+2)
        {
            ll LF = f(i, ind-1, 0, exp);
            ll LT = f(i, ind-1, 1, exp);
            ll RT = f(ind+1, j, 1, exp);
            ll RF = f(ind+1, j, 0, exp);

            if(exp[ind] == '&')
            {
                if(isTrue) ways = (ways + (RT * LT)%mod)%mod;
                else ways = (ways + (RF * LF)%mod + (LT*RF)%mod + (LF*RT)%mod)%mod;
            }
            else if(exp[ind] == '|')
            {
                if(isTrue) ways = (ways + (LT*RT)%mod + (RT*LF)%mod + (RF*LT)%mod)%mod;
                else ways = (ways + (RF*LF)%mod)%mod;
            }
            else
            {
                //XOR, t^t = f, t^f = t, f^t = t, f^f = f.
                if(isTrue) ways = (ways + (RF*LT)%mod + (RT*LF)%mod)%mod;
                else ways = (ways + (RF*LF)%mod + (RT*LT)%mod)%mod;
            }
        }

        return ways;
    }
public:
    long long parseBoolExpr(string expression) {
        return f(0,expression.size()-1, 1, expression);
    }
};

int main()
{
    string exp = "t^f|f|t";

    Solution obj;
    cout << "Number of ways to evaluate the expression to true is " << obj.parseBoolExpr(exp) << endl;

    return 0;
}