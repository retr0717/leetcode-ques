#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int val = 0, purchase = prices[0], maxP = 0;
    for (int i = 1; i < prices.size(); i++) {
      val = prices[i] - purchase;
      if (val < 0)
        purchase = prices[i];
      else
        maxP = max(val, maxP);
    }

    return maxP;
  }
};
int main() {
  Solution sol;
  vector<int> nums = {7, 6, 4, 3, 1};
  int profit = sol.maxProfit(nums);
  cout << profit << endl;
}
