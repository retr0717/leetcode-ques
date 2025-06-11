#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisJointSet{
public:
    vector<int> parent, size;

    DisJointSet(int n)
    {
        parent.resize(n+1);
        size.resize(n+1, 1);

        for(int i = 0 ; i <= n ; i++)
            parent[i] = i;
    }

    int findParent(int node)
    {
        if(node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int uParent = findParent(u);
        int vParent = findParent(v);

        if(uParent == vParent) return;

        if(size[uParent] < size[vParent])
        {
            parent[uParent] = vParent;
            size[vParent] += size[uParent];
        }
        else
        {
            parent[vParent] = uParent;
            size[uParent] += size[vParent];
        }
    }
};

class Solution {
private:
    bool isValid(int row, int col, int n)
    {
        return row >= 0 && row < n && col >= 0 && col < n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisJointSet ds(n*n);

        //calculating the size of each component.
        for(int row = 0 ; row < n ; row++)
        {
            for(int col = 0 ; col < n ; col++)
            {
                if(grid[row][col] == 0) continue;

                int dr[] = {-1 , 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for(int i = 0 ; i < 4 ; i++)
                {
                    int adjRow = row + dr[i];
                    int adjCol = col + dc[i];

                    if(isValid(adjRow, adjCol, n) && grid[adjRow][adjCol] == 1)
                    {
                        int nodeNo = row * n + col;
                        int adjNodeNo = adjRow * n + adjCol;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        int mSize = 0;

        //finding the flip position to find the largest component.
        for(int row = 0 ; row < n ; row++)
        {
            for(int col = 0 ; col < n ; col++)
            {
                if(grid[row][col] == 1) continue;

                int dr[] = {-1 , 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                set<int> components;
                for(int i = 0 ; i < 4 ; i++)
                {
                    int adjRow = row + dr[i];
                    int adjCol = col + dc[i];

                    if(isValid(adjRow, adjCol, n) && grid[adjRow][adjCol] == 1)
                    {
                        int adjNodeNo = adjRow * n + adjCol;
                        components.insert(ds.findParent(adjNodeNo));
                    }
                }

                //calculate the size.
                int cSize = 0;
                for(auto &it : components)
                {
                    cSize += ds.size[it];
                }

                mSize = max(mSize, cSize+1);
            }
        }

        for(int cellNo = 0; cellNo < (n*n) ; cellNo++)
        {
            mSize = max(mSize , ds.size[ds.findParent(cellNo)]);
        }

        return mSize;
    }
};
