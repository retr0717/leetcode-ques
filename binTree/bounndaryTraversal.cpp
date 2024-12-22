#include <bits/stdc++.h>
using namespace std;
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
bool isLeafNode(TreeNode<int> *root) {
  return (root->left == NULL && root->right == NULL);
}

void addLeftBound(TreeNode<int> *root, vector<int> &res) {
  TreeNode<int> *curr = root;
  while (curr) {
    if (!isLeafNode(curr)) {
      res.push_back(curr->val);
    }
    if (curr->left) {
      curr = curr->left;
    } else {
      curr = curr->right;
    }
  }
}

void addLeaves(TreeNode<int> *root, vector<int> &res) {
  if (!root)
    return;
  if (isLeafNode(root)) {
    res.push_back(root->val);
    return;
  }
  if (root->left)
    addLeaves(root->left, res);
  if (root->right)
    addLeaves(root->right, res);
}

void addRightBound(TreeNode<int> *root, vector<int> &res) {
  TreeNode<int> *curr = root;
  vector<int> temp;
  while (curr) {
    if (!isLeafNode(curr)) {
      temp.push_back(curr->val);
    }
    if (curr->right) {
      curr = curr->right;
    } else {
      curr = curr->left;
    }
  }

  for (int i = temp.size() - 1; i >= 0; --i) {
    res.push_back(temp[i]);
  }
}

vector<int> boundaryTraversal(TreeNode<int> *root) {
  vector<int> res;
  if (!root)
    return res;

  if (!isLeafNode(root))
    res.push_back(root->val);

  addLeftBound(root->left, res);
  addLeaves(root, res);
  addRightBound(root->right, res);

  return res;
}
