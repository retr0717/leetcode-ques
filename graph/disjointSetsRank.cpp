#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSets {
public:
    vector<int> parent, rank;
public:
    DisjointSets(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i = 0 ; i < n ; i++)
            parent[i] = i;
    }

    int findParent(int node){
        if( node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u , int v){
        int uParent = findParent(u);
        int vParent = findParent(v);
        if(uParent == vParent) return;
        //path compression.
        if(rank[uParent] < rank[vParent]){
            parent[uParent] = vParent;
        } else if(rank[vParent] < rank[uParent]){
            parent[vParent] = uParent;
        } else {
            parent[vParent] = uParent;
            rank[uParent]++;
        }
    }
};

int main()
{
    DisjointSets ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    if(ds.findParent(3) == ds.findParent(7)) {
        cout << "same component." << endl;
    } else {
        cout << "different components." << endl;
    }

    ds.unionByRank(3, 7);
    if(ds.findParent(3) == ds.findParent(7)) {
        cout << "same component." << endl;
    } else {
        cout << "different components." << endl;
    }

    for(int i = 1; i <= 5; i++){
        cout << "Parent of " << i << " is: " << ds.findParent(i) << endl;
    }
    cout << "Rank of each node:" << endl;
    for(int i = 1; i <= 5; i++){
        cout << "Rank of " << i << " is: " << ds.rank[ds.findParent(i)] << endl;
    }
    cout << "Union of 1 and 5: ";
    ds.unionByRank(1, 5);
    for(int i = 1; i <= 5; i++){
        cout << "Parent of " << i << " is: " << ds.findParent(i) << endl;
    }
    cout << "Rank of each node after union:" << endl;
    for(int i = 1; i <= 5; i++){
        cout << "Rank of " << i << " is: " << ds.rank[ds.findParent(i)] << endl;
    }
    cout << "Final parent array: ";
    for(int i = 1; i <= 5; i++){
        cout << ds.findParent(i) << " ";
    }
    cout << endl;
    cout << "Final rank array: ";
    for(int i = 1; i <= 5; i++){
        cout << ds.rank[ds.findParent(i)] << " ";
    }
    cout << endl;
    cout << "Final parent array after path compression: ";
    for(int i = 1; i <= 5; i++){
        cout << ds.findParent(i) << " ";
    }
    cout << endl;
    return 0;
}