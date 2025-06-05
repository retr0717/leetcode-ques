#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSet{
	public:
		vector<int> parent, size;
	public:
		DisjointSet(int n)
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
			else if(size[vParent] < size[uParent])
			{
				parent[vParent] = uParent;
				size[uParent] += size[vParent];
			}
			else{
				parent[vParent] = uParent;
				size[uParent] += size[vParent];
			}
		}
};

int kruskalMST(int n, vector<vector<int>> &edges)
{
	vector<pair<int, pair<int, int>>> edgeList;
	int mstWt = 0;


	for(auto &it : edges)
	{
		int u = it[0];
		int v = it[1];
		int wt = it[2];

		edgeList.push_back({wt, {u, v}});
	}

	DisjointSet ds(n);
	sort(edgeList.begin(), edgeList.end());

	for(auto &e: edgeList)
	{
		int wt = e.first;
		int u = e.second.first;
		int v = e.second.second;

		if(ds.findParent(u) != ds.findParent(v))
		{
			mstWt += wt;
			ds.unionBySize(u, v);
		}
	}

	return mstWt;
}

