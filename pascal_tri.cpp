#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int nCr(int n, int r) {
    long long res = 1;

    for (int i = 0; i < r; i++) {
      res = res * (n - i);
      res = res / (i + 1);
    }

    return (int)res;
  }

public:
  vector<vector<int>> generate(int n) {

    vector<vector<int>> result;

    for (int row = 1; row <= n; row++) {
      vector<int> temp;
      for (int col = 1; col <= row; col++) {
        temp.push_back(nCr(row - 1, col - 1));
      }

      result.push_back(temp);
    }

    return result;
  }
};

int main() {
  Solution s;
  vector<vector<int>> result = s.generate(5);
  for (auto &v : result) {
    for (int &c : v) {
      cout << c << " ";
    }
    cout << endl;
  }
}
