
#include <bits/stdc++.h>
using namespace std;

map<char, vector<char>> mp;
vector<string> result;

void helper(string s, int index, string str) {
  if (index == s.length()) {
    result.push_back(str);
  } else {
    char keyPressed = s[index];
    vector<char> possibilities = mp[keyPressed];
    for (char c : possibilities) {
      helper(s, index + 1, str + c);
    }
  }
}

vector<string> combinations(string s) {
  result.clear();
  if (s.length() == 0)
    return result;

  mp['2'] = {'a', 'b', 'c'};
  mp['3'] = {'d', 'e', 'f'};
  mp['4'] = {'g', 'h', 'i'};
  mp['5'] = {'j', 'k', 'l'};
  mp['6'] = {'m', 'n', 'o'};
  mp['7'] = {'p', 'q', 'r', 's'};
  mp['8'] = {'t', 'u', 'v'};
  mp['9'] = {'w', 'x', 'y', 'z'};

  helper(s, 0, "");
  return result;
}
