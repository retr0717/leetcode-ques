#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  void markParent(TreeNode *root,
                  unordered_map<TreeNode *, TreeNode *> &parentTrack,
                  TreeNode *target) {
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      TreeNode *temp = q.front();
      q.pop();
      if (temp->left) {
        parentTrack[temp->left] = temp;
        q.push(temp->left);
      }
      if (temp->right) {
        parentTrack[temp->right] = temp;
        q.push(temp->right);
      }
    }
  }

  vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    unordered_map<TreeNode *, TreeNode *> parentTrack;
    markParent(root, parentTrack, target);

    unordered_map<TreeNode *, bool> visited;
    queue<TreeNode *> q;
    q.push(target);
    visited[target] = true;
    int curLevel = 0;

    while (!q.empty()) {
      int size = q.size();
      if (curLevel++ == k)
        break;
      for (int i = 0; i < size; i++) {
        TreeNode *current = q.front();
        q.pop();
        if (current->left && !visited[current->left]) {
          q.push(current->left);
          visited[current->left] = true;
        }
        if (current->right && !visited[current->right]) {
          q.push(current->right);
          visited[current->right] = true;
        }

        if (parentTrack[current] && !visited[parentTrack[current]]) {
          q.push(parentTrack[current]);
          visited[parentTrack[current]] = true;
        }
      }
    }

    vector<int> result;
    while (!q.empty()) {
      TreeNode *current = q.front();
      q.pop();
      result.push_back(current->val);
    }

    return result;
  }
};
