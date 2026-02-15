#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int largeRecArea(vector<int> &hist)
    {
        stack<int> st;
        int maxA = 0;
        int n = hist.size();

        for(int i = 0 ; i <= n ; i++)
        {
            while(!st.empty() && (i == n || hist[st.top()] >= hist[i]))
            {
                int height = hist[st.top()];
                st.pop();
                int width;
                if(st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                
                maxA = max(maxA, width*height);
            }

            st.push(i);
        }

        return maxA;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> height(m, 0);
        int maxArea = 0;
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }

            int area = largeRecArea(height);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

int main()
{
    vector<vector<char>> matrix = {{'1','0','1','0','0'},
                                   {'1','0','1','1','1'},
                                   {'1','1','1','1','1'},
                                   {'1','0','0','1','0'}};

    Solution obj;

    cout<<obj.maximalRectangle(matrix)<<endl;

    return 0;
}