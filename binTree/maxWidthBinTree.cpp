#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  int widthOfBinaryTree(TreeNode *root) {
    if (!root)
      return 0;

    queue<pair<TreeNode *, long>> q;
    int ans = 0;
    q.push({root, (long)0});

    while (!q.empty()) {
      int mmin = q.front().second;
      int size = q.size();
      int first, last;

      for (int i = 0; i < size; i++) {
        int curId = q.front().second - mmin;
        TreeNode *node = q.front().first;
        q.pop();
        if (i == 0)
          first = curId;
        if (i == size - 1)
          last = curId;
        if (node->left)
          q.push({node->left, (long)curId * 2 + 1});
        if (node->right)
          q.push({node->right, (long)curId * 2 + 2});
      }

      ans = max(ans, last - first + 1);
    }

    return ans;
  }
};
