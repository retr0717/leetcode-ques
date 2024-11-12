//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  void print_divisors(int n) {

    vector<int> r;
    for (int i = 1; (i * i) <= n; i++) {
      if (n % i == 0) {
        r.push_back(i);

        if (n / i != i)
          r.push_back(n / i);
      }
    }

    sort(r.begin(), r.end());
    for (auto i : r)
      cout << i << " ";
  }
};

//{ Driver Code Starts.
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    Solution ob;
    ob.print_divisors(n);
    cout << endl;

    cout << "~" << "\n";
  }
  return 0;
}
// } Driver Code Ends
