#include <bits/stdc++.h>
using namespace std;

int f(vector<vector<int>> grid, int m, int n)
{
        //base case if the path exists.
        if( m == 0 && n == 0 ) return 1;

        //base if the path doesn't exists.
        if( m < 0 || n < 0 ) return 0;

	if(grid[m][n] == 1 ) return 0;
        
	//move up.m-1, 
        int up = f(grid, m-1, n);

        //move left.
        int left = f(grid, m, n-1);

        return up + left;
}

int main()
{
//	vector<vector<int>> arr = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
	vector<vector<int>> arr = {{0, 1}, {0, 0}};

	int m = arr.size();
	int n = arr[0].size();

        int ans = f(arr, m-1, n-1);

        cout<<"Ans : "<<ans<<endl;

        return 0;
}
