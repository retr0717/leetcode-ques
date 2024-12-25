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
  int heightRight(TreeNode *node) {
    int height = 0;

    while (node) {
      height++;
      node = node->right;
    }

    return height;
  }

  int heightLeft(TreeNode *node) {
    int height = 0;
    while (node) {
      height++;
      node = node->left;
    }

    return height;
  }

  int countNodes(TreeNode *root) {
    if (root == NULL)
      return 0;

    int lh = heightLeft(root);
    int rh = heightRight(root);
    if (lh == rh)
      return (1 << lh) - 1;

    return countNodes(root->left) + countNodes(root->right) + 1;
  }
};
