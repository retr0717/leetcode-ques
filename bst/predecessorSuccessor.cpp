#include <bits/stdc++.h>
using namespace std;
/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left),
right(right) {}
    };

*************************************************************/

pair<int, int> predecessorSuccessor(TreeNode *root, int key) {
  int successor = -1;
  int predecessor = -1;

  TreeNode *curr = root;

  while (curr != NULL) {
    if (key >= curr->data)
      curr = curr->right;
    else {
      successor = curr->data;
      curr = curr->left;
    }
  }

  curr = root;
  while (curr != NULL) {
    if (key <= curr->data)
      curr = curr->left;
    else {
      predecessor = curr->data;
      curr = curr->right;
    }
  }

  return {predecessor, successor};
}
