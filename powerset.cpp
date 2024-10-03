#include <bits/stdc++.h>
using namespace std;

void bfPowersetofString(string s) {
  int n = s.length();
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      if (i & (1 << j))
        cout << s[j];
    }
    cout << endl;
  }
}

int main() {
  string s = "abc";
  bfPowersetofString(s);
  return 0;
}
