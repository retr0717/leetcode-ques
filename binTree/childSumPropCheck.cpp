#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *left, *right;
  Node() {
    this->data = 0;
    left = NULL;
  }
  Node(int data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
  Node(int data, Node *left, Node *right) {
    this->data = data;
    this->left = left;
    this->right = right;
  }
};

bool isParentSum(Node *root) {
  if (root == NULL)
    return true;

  if (root->left == NULL && root->right == NULL)
    return true;

  int child = 0;
  if (root->left)
    child += root->left->data;

  if (root->right)
    child += root->right->data;

  if (child != root->data)
    return false;

  bool leftValid = isParentSum(root->left);
  bool rightValid = isParentSum(root->right);

  return leftValid && rightValid;
}
