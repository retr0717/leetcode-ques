#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findCombinations(vector<int>& arr, vector<vector<int>>& ans,
                          vector<int>& ds, int target, int index, int n) {
        if (index == n) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        // pick
        if (arr[index] <= target) {
            ds.push_back(arr[index]);
            findCombinations(arr, ans, ds, target - arr[index], index, n);

            // not pick.
            ds.pop_back();
        }

        findCombinations(arr, ans, ds, target, index + 1, n);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        findCombinations(candidates, ans, ds, target, 0, candidates.size());

        return ans;
    }
};

int main()
{
    Solution s;
    vector < int > v {2,3,6,7};
    int target = 7;

    vector<vector<int>> ans = s.combinationSum(v, target);

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