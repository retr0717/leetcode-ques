#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisJointSet{
public:
    vector<int> parent, size;
public:
    DisJointSet(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
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

        if(size[uParent] < size[vParent])
        {
            parent[uParent] = vParent;
            size[vParent] += size[uParent];
        }
        else{
            parent[vParent]  = uParent;
            size[uParent] += size[vParent];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisJointSet ds(n);

        //calculate extra edges.
        //calcuate no of components.
        int extra = 0;
        for(auto &it : connections)
        {
            int u = it[0];
            int v = it[1];

            if(ds.findParent(u) == ds.findParent(v)) extra++;
            else ds.unionBySize(u, v);
        }

        int components = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(ds.parent[i] == i) components++;
        }

        int edgeNeed = components - 1;
        if(extra >= edgeNeed) return edgeNeed;

        return -1;
    }
};
