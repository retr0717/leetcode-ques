#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Disjoint Set Union (DSU) with Union by Rank and Path Compression
class DisjointSets {
public:
    vector<int> parent, size;
public:
    DisjointSets(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i = 0 ; i <= n ; i++)
            parent[i] = i;
    }

    int findParent(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void UnionBySize(int u, int v){
        int uParent = findParent(u);
        int vParent = findParent(v);

        if(uParent == vParent) return;

        //size comparison
        if(size[uParent] < size[vParent]){
            parent[uParent] = vParent;
            size[vParent] += size[uParent];
        }
        else{
            parent[vParent] = uParent;
            size[uParent] += size[vParent];
        }
    }
};

int main()
{
    DisjointSets ds(7);
    ds.UnionBySize(1, 2);
    ds.UnionBySize(2, 3);
    ds.UnionBySize(4, 5);
    ds.UnionBySize(6, 7);
    ds.UnionBySize(5, 6);

    if(ds.findParent(3) == ds.findParent(7)) {
        cout << "same component." << endl;
    } else {
        cout << "different components." << endl;
    }

    ds.UnionBySize(3, 7);
    if(ds.findParent(3) == ds.findParent(7)) {
        cout << "same component." << endl;
    } else {
        cout << "different components." << endl;
    }
    
    return 0;
}