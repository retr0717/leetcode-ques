#include <bits/stdc++.h>
using namespace std;

int maxCost(int index,int length, vector<int>& price)
{
	if(index == 0){
		return length * price[0];
	}

	int nTake = maxCost(index-1, length, price);
	int rodLength = index +1;
	int take = INT_MIN;
	if(rodLength <= length)
		take = price[index] + maxCost(index, length-rodLength, price);

	return max(take, nTake);
}

int cutRod(vector<int> &price, int n)
{
	return maxCost(price.size()-1, n, price);
}
