#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findCombinations(vector<int>& arr, vector<vector<int>>& ans,
                          vector<int>& ds, int target, int index, int n) {

        if (target == 0) 
        {
            ans.push_back(ds);
            return;
        }

    for(int i = index ; i < n ; i++)
    {
        if(i > index && arr[i] == arr[i - 1])
            continue;

        if (arr[i] > target) break;

        ds.push_back(arr[i]);
        findCombinations(arr, ans, ds, target - arr[i], i + 1, n);
        ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        findCombinations(candidates, ans, ds, target, 0, candidates.size());
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {10,1,2,7,6,1,5};
    int target = 8;

    vector<vector<int>> ans = s.combinationSum2(arr, target);
    for(auto x : ans)
    {
        cout<<"[ ";
        for(auto y : x)
        {
            cout<<y;
            if(x.size() != 1)
                cout<<" ,";
        }
        cout<<" ], ";
    }
    cout<<endl;
}