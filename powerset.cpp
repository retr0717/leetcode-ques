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

void powersetUsingRecursion(int i, string s, string f) {
  if (i == s.length()) {
    cout << f << endl;
    return;
  }
  powersetUsingRecursion(i + 1, s, f);
  powersetUsingRecursion(i + 1, s, f + s[i]);
}

int main() {
  string s = "abc";
  bfPowersetofString(s);
  cout << endl;
  bfPowersetofString(s);
  return 0;
}
