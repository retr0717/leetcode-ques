#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int MinPath(int i , int j, vector<vector<int>> arr, int n)
    {
        if(i == n-1) return arr[n-1][j];

        int down = arr[i][j] + MinPath(i+1, j, arr, n);
        int diag = arr[i][j] + MinPath(i+1, j+1, arr, n);

        return min(down, diag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return MinPath(0, 0, triangle, triangle.size());
    }
};
