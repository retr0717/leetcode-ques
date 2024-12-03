#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string removeKdigits(string num, int k) {
    stack<char> st;

    for (int i = 0; i < num.length(); i++) {
      while (!st.empty() && k > 0 && (st.top() - '0') > (num[i] - '0')) {
        st.pop();
        k -= 1;
      }

      st.push(num[i]);
    }

    while (k > 0) {
      st.pop();
      k -= 1;
    }

    if (st.empty())
      return "0";

    string result = "";
    while (!st.empty()) {
      result += st.top();
      st.pop();
    }

    while (result.length() > 0 && result.back() == '0')
      result.pop_back();

    reverse(result.begin(), result.end());

    if (result.empty())
      return "0";

    return result;
  }
};
