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
  TreeNode *buildTreePostIn(vector<int> &inorder, int inStart, int inEnd,
                            vector<int> &postorder, int postStart, int postEnd,
                            map<int, int> &hm) {
    if (postStart > postEnd || inStart > inEnd)
      return NULL;

    TreeNode *root = new TreeNode(postorder[postEnd]);

    int inRoot = hm[postorder[postEnd]];
    int numsLeft = inRoot - inStart;

    root->left = buildTreePostIn(inorder, inStart, inRoot - 1, postorder,
                                 postStart, postStart + numsLeft - 1, hm);
    root->right = buildTreePostIn(inorder, inRoot + 1, inEnd, postorder,
                                  postStart + numsLeft, postEnd - 1, hm);

    return root;
  }

  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (inorder.size() != postorder.size())
      return NULL;

    map<int, int> hm;
    for (int i = 0; i < inorder.size(); i++)
      hm[inorder[i]] = i;

    return buildTreePostIn(inorder, 0, inorder.size() - 1, postorder, 0,
                           postorder.size() - 1, hm);
  }
};
