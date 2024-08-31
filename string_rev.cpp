#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    int left = 0;
    int right = s.length() - 1;
    string temp = "";
    string ans = "";

    // Trim leading spaces
    while (left <= right && s[left] == ' ') {
      left++;
    }

    // Trim trailing spaces
    while (right >= left && s[right] == ' ') {
      right--;
    }

    while (left <= right) {
      char ch = s[left];

      if (ch != ' ') {
        // Add characters to form a word
        temp += ch;
      } else if (ch == ' ' && temp != "") {
        if (ans != "") {
          ans = temp + " " + ans;
        } else {
          ans = temp;
        }
        temp = ""; // Reset
      }
      left++;
    }

    // Add the last word to the result
    if (temp != "") {
      if (ans != "") {
        ans = temp + " " + ans;
      } else {
        ans = temp;
      }
    }

    return ans;
  }
};

int main() {
  string s = " hello world ";
  Solution sol;
  string ans = sol.reverseWords(s);
  cout << ans << endl;
  return 0;
}
