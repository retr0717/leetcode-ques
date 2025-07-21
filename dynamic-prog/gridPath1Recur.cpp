#include <bits/stdc++.h>
using namespace std;

int f(int m, int n)
{
	//base case if the path exists.
	if( m == 0 && n == 0 ) return 1;

	//base if the path doesn't exists.
	if( m < 0 || n < 0 ) return 0;

	//move up.
	int up = f(m-1, n);

	//move left.
	int left = f(m, n-1);

	return up + left;
}

int main()
{
	int m = 3, n = 7;

	int ans = f(m-1, n-1);

	cout<<"Ans : "<<ans<<endl;

	return 0;
}
