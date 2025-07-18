#include <bits/stdc++.h>
using namespace std;

int MaxMerit(int day, int last, vector<vector<int>> &activity)
{
	int maxVal = 0;
	if(day == 0)
	{
		for(int i = 0 ; i < 3 ; i++)
		{
			if(i != last)
				maxVal = max(maxVal, activity[0][i]);
		}

		return maxVal;
	}

	maxVal = 0;

	for(int i = 0 ; i < 3 ; i++)
	{
		if( i != last)
		{
			int points = activity[day][i] + MaxMerit(day - 1, i, activity);
			maxVal = max(maxVal, points);
		}
	}

	return maxVal;
}

int main()
{
	vector<vector<int>> arr = {{18, 11, 19}, {4, 13, 7}, {1, 8, 13}};
	int ans = MaxMerit(2, 2, arr);
	cout<<"Answer : "<<ans<<endl;

	return 0;
}
