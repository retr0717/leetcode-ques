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
        for(int i = 0 ; i < n ; i++)
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

        //larger to small connection.
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

bool isValid(int adr, int adc, int n, int m)
{
    return adr >= 0 && adr < n && adc >= 0 && adc < m;
}

vector<int> numberOfIslandII(int n, int m, vector<vector<int>>& queries, int q)
{
    DisJointSet ds(n*m);
    int visited[n][m];
    memset(visited, 0, sizeof(visited));
    int count = 0;
    vector<int> ans;

    for(auto &it: queries)
    {
        int row = it[0];
        int col = it[1];

        if(visited[row][col] == 1)
        {
            ans.push_back(count);
            continue;
        }

        visited[row][col] = 1;
        count++;

        /*
        check for the adjacent cells.

        row - 1, col
        row , col + 1
        row + 1, col
        row , col - 1

        */

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for(int index = 0; index < 4 ; index++)
        {
            //boundary check.
            int adr = row + dr[index];
            int adc = col + dc[index];
            if(isValid(adr, adc, n, m))
            {
                //check adjacent is a land.
                if(visited[adr][adc] == 1)
                {
                    //check if its already connected.
                    int nodeNo = (row * m) + col;
                    int adjNodeNo = (adr *m)+ adc;
                    if(ds.findParent(nodeNo) != ds.findParent(adjNodeNo))
                    {
                        //if not connect them.
                        ds.unionBySize(nodeNo, adjNodeNo);
                        count--;// decrement the count.
                    }
                }
            }
        }

        ans.push_back(count);
    }    

    return ans;
}
