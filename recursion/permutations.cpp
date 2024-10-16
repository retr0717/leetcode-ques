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
private:
    void permutation2(int index, vector<vector<int>>& ans, vector<int>& nums)
    {
        if(index == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for(int i = index ; i < nums.size() ; i++)
        {
            swap(nums[index],nums[i]);
            permutation2(index+1, ans, nums);
            swap(nums[index], nums[i]);
        }
    }
public:
    vector<vector<int>> permute2(vector<int>& nums) {
        vector<vector<int>> ans;
        permutation2(0, ans, nums);
        return ans;
    }
};

int main()
{
    vector<int> arr = {1,2,4};
    Solution s;
    //vector<vector<int>> ans = s.permute(arr);
    vector<vector<int>> ans = s.permute2(arr);
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