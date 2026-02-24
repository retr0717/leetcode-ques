#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[2];

    Node() {
        links[0] = NULL;
        links[1] = NULL;
    }

    bool containsKey(int ind)
    {
        return (links[ind] != NULL);
    }

    Node* get(int bit)
    {
        return links[bit];
    }

    void put(int bit, Node* node)
    {
        links[bit] = node;
    }
};

class Trie{
    private:
        Node* root;

    public: 
        Trie(){
            root = new Node();
        }
    
    public:
        void insert(int num)
        {
            Node* node = root;
            for(int i = 31; i >= 0 ; i--)
            {
                int bit = (num >> i) & 1;
                if(!node->containsKey(bit)){
                    node->put(bit, new Node());
                }

                node = node->get(bit);
            }
        }

        int getMax(int num)
        {
            int maxNum = 0;
            Node* node = root;
            for(int i = 31; i >= 0 ; i--)
            {
                int bit = (num >> i) & 1;
                if(node->containsKey(1-bit))
                {
                    maxNum = maxNum | (1 << i);
                    node = node->get(1-bit);
                }
                else
                {
                    node = node->get(bit);
                }
            }

            return maxNum;
        }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int,int>>> oQ;
        int q = queries.size();

        for(int i = 0 ; i < q; i++)
        {
            oQ.push_back({queries[i][1],{queries[i][0], i}});
        }
        sort(oQ.begin(), oQ.end());

        vector<int> ans(q, 0);
        int n = nums.size();
        int ind = 0;

        for(int i = 0 ; i < q ; i++)
        {
            int mi = oQ[i].first;
            int xi = oQ[i].second.first;
            int qInd = oQ[i].second.second;

            while(ind < n && nums[ind] <= mi)
            {
                trie.insert(nums[ind]);
                ind++;
            }

            if(ind == 0) ans[qInd] = -1;
            else ans[qInd] = trie.getMax(xi);
        }

        return ans;
    }
};

int main()
{
    vector<int> nums = {0,1,2,3,4};
    vector<vector<int>> queries = {{3,1},{1,3},{5,6}};
    Solution sol;
    vector<int> ans = sol.maximizeXor(nums, queries);
    for(int i : ans) cout << i << " ";
}