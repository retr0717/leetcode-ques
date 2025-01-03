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
  bool isValidBST(TreeNode *root) {
    long minVal = LONG_MIN;
    long maxVal = LONG_MAX;
    return isBst(root, minVal, maxVal);
  }

  bool isBst(TreeNode *root, long minVal, long maxVal) {
    if (root == NULL)
      return true;
    if (root->val >= maxVal || root->val <= minVal)
      return false;

    return isBst(root->left, minVal, root->val) &&
           isBst(root->right, root->val, maxVal);
  }
};
