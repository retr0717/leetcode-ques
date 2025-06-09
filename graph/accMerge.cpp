#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class DisJointSet {
public:
    vector<int> parent, size;

    DisJointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int uParent = findParent(u);
        int vParent = findParent(v);
        if (uParent == vParent) return;

        if (size[uParent] < size[vParent]) {
            parent[uParent] = vParent;
            size[vParent] += size[uParent];
        } else {
            parent[vParent] = uParent;
            size[uParent] += size[vParent];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisJointSet ds(n);

        unordered_map<string, int> mapMail;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mapMail.find(mail) == mapMail.end())
                    mapMail[mail] = i;
                else
                    ds.unionBySize(i, mapMail[mail]);
            }
        }

        vector<vector<string>> mergedMail(n);
        for (auto& it : mapMail) {
            string mail = it.first;
            int node = ds.findParent(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergedMail[i].empty()) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]); // Account name
            for (auto& mail : mergedMail[i])
                temp.push_back(mail);
            ans.push_back(temp);
        }

        return ans;
    }
};

