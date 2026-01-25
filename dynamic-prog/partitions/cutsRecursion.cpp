#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(int i, int j, vector<int>& cuts)
    {
        if(i > j) return 0;

        int mini = INT_MAX;
        
        for(int index = i; index <= j; index++)
        {
            int cost = cuts[j+1] - cuts[i-1] + f(i, index-1, cuts) + f(index+1, j, cuts);

            mini = min(cost, mini);
        }

        return mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        return f(1, c, cuts);
    }
};

int main()
{
    int n = 7;
    vector<int> cuts = {1, 3, 4, 5};

    Solution obj;
    cout << "Minimum cost to cut the stick is " << obj.minCost(n, cuts) << endl;

    return 0;
}