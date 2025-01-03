
#include <bits/stdc++.h>
using namespace std;

/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int findMaxDistance(map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &mpp,
                    BinaryTreeNode<int> *target) {
  queue<BinaryTreeNode<int> *> q;
  q.push(target);
  map<BinaryTreeNode<int> *, int> visited;
  visited[target] = 1;
  int maxi = 0;
  while (!q.empty()) {
    int sz = q.size();
    int fl = 0;
    for (int i = 0; i < sz; i++) {
      auto node = q.front();
      q.pop();
      if (node->left && !visited[node->left]) {
        fl = 1;
        visited[node->left] = 1;
        q.push(node->left);
      }
      if (node->right && !visited[node->right]) {
        fl = 1;
        visited[node->right] = 1;
        q.push(node->right);
      }

      if (mpp[node] && !visited[mpp[node]]) {
        fl = 1;
        visited[mpp[node]] = 1;
        q.push(mpp[node]);
      }
    }

    if (fl)
      maxi++;
  }

  return maxi;
}

BinaryTreeNode<int> *
bfsToMapParents(BinaryTreeNode<int> *root,
                map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &mpp,
                int start) {
  queue<BinaryTreeNode<int> *> q;
  q.push(root);
  BinaryTreeNode<int> *res;

  while (!q.empty()) {
    BinaryTreeNode<int> *node = q.front();
    if (node->data == start)
      res = node;
    q.pop();
    if (node->left) {
      mpp[node->left] = node;
      q.push(node->left);
    }
    if (node->right) {
      mpp[node->right] = node;
      q.push(node->right);
    }
  }

  return res;
}

int timeToBurnTree(BinaryTreeNode<int> *root, int start) {
  map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> mpp;
  BinaryTreeNode<int> *target = bfsToMapParents(root, mpp, start);
  int maxi = findMaxDistance(mpp, target);
  return maxi;
}
