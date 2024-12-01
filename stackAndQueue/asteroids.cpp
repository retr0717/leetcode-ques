#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> asteroidCollision(vector<int> &asteroids) {
    vector<int> inputs = asteroids;
    vector<int> stack;

    for (int i = 0; i < inputs.size(); i++) {
      if (inputs[i] > 0)
        stack.push_back(inputs[i]);
      else {
        while (!stack.empty() && stack.back() > 0 &&
               stack.back() < abs(inputs[i]))
          stack.pop_back();

        if (!stack.empty() && stack.back() == abs(inputs[i]))
          stack.pop_back();
        else if (stack.empty() || stack.back() < 0)
          stack.push_back(inputs[i]);
      }
    }

    return stack;
  }
};
