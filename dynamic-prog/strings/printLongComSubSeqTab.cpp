#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        if(n == 1 && m == 1)
        {
            if(text1[0] != text2[0]) return 0;
        }

        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

        for(int i = 0 ; i < n ; i++) dp[i][0] = 0;
        for(int j = 0 ; j < m ; j++) dp[0][j] = 0;

        for(int i = 1; i <= n ; i++)
        {
            for(int j = 1 ; j <= m ; j++)
            {
                //match found.
                if(text1[i-1] == text2[j-1]) 
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);//not a match.
            }
        }
		
	int len = dp[n][m];
	string ans = "";
	for(int i = 0 ; i < len ; i++) ans += '$';

	int index = len-1;
	int i = n, j = m;

	while(i > 0 && j > 0)
	{
		if(text1[i-1] == text2[j-1])
		{
			ans[index] = text1[i-1];
			index--;
			i--;
			j--;
		}
		else if(dp[i-1][j] > dp[i][j-1]) i--;
		else j--;
	}

	cout<<ans<<endl;

        return dp[n][m];
    }
};

int main()
{	
	Solution sol;
	string text1 = "abcde";
	string text2 = "bdgek";

	int ans = sol.longestCommonSubsequence(text1, text2);
	cout<<ans<<endl;

	return 0;
}

