#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void permutation(vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds, int freq[])
    {
        if(ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }

        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(!freq[i])
            {
                freq[i] = 1;
                ds.push_back(nums[i]);
                permutation(nums, ans, ds, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        for (int i = 0; i < nums.size(); i++) freq[i] = 0;
        permutation(nums, ans, ds, freq);
        return ans;
    }
};

int main()
{
    vector<int> arr = {1,2,4};
    Solution s;
    vector<vector<int>> ans = s.permute(arr);
    for(auto s : ans)
    {
        cout<<"[ ";
        for(auto x : s)
        {
            cout<<x<<",";
        }
        cout<<"]"<<endl;
    }
    cout<<endl;
    return 0;
}