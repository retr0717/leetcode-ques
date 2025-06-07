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
            parent[i]  = i;
    }

    int findParent(int node)
    {
        if(node == parent[node])
            return node;
        
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u , int v)
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
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;
        for(auto &it: stones)
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisJointSet ds(maxRow+maxCol+1);
        unordered_map<int, int> stoneNodes;

        for(auto &it : stones)
        {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int count = 0;
        for(auto &it : stoneNodes)
        {
            if(ds.findParent(it.first) == it.first)
                count++;
        }

        return stones.size() - count;
    }
};
