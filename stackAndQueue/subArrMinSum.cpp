#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findNse(vector<int> &arr) {
    vector<int> nse(arr.size(), 0);
    stack<int> st;
    for (int i = arr.size() - 1; i >= 0; i--) {
      while (!st.empty() && arr[st.top()] >= arr[i])
        st.pop();

      nse[i] = st.empty() ? arr.size() : st.top();

      st.push(i);
    }

    return nse;
  }

  vector<int> findPse(vector<int> &arr) {
    vector<int> pse(arr.size(), 0);
    stack<int> st;
    for (int i = 0; i < arr.size(); i++) {
      while (!st.empty() && arr[st.top()] > arr[i])
        st.pop();

      pse[i] = st.empty() ? -1 : st.top();

      st.push(i);
    }

    return pse;
  }

  int sumSubarrayMins(vector<int> &arr) {
    vector<int> nse = findNse(arr);
    vector<int> pse = findPse(arr);
    int mod = 1e9 + 7;
    int tot = 0, left = 0, right = 0;

    for (int i = 0; i < arr.size(); i++) {
      left = i - pse[i];
      right = nse[i] - i;
      tot = (tot + (right * left * 1LL * arr[i]) % mod) % mod;
    }

    return tot;
  }
};
