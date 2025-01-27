#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
  int data;
  TreeNode *left, *right;
  TreeNode() : data(0), left(NULL), right(NULL) {}
  TreeNode(int x) : data(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : data(x), left(left), right(right) {}
};

void InTraverse(TreeNode *root, vector<int> &inOrd, vector<int> &Pre,
                vector<int> &post) {

  if (root == NULL)
    return;

  stack<pair<TreeNode *, int>> st;
  st.push({root, 1});

  while (!st.empty()) {
    auto it = st.top();
    st.pop();

    if (it.second == 1) {
      Pre.push_back(it.first->data);
      it.second++;
      st.push(it);

      if (it.first->left != NULL)
        st.push({it.first->left, 1});
    } else if (it.second == 2) {
      inOrd.push_back(it.first->data);
      it.second++;
      st.push(it);

      if (it.first->right != NULL)
        st.push({it.first->right, 1});
    } else
      post.push_back(it.first->data);
  }
}

vector<vector<int>> getTreeTraversal(TreeNode *root) {
  vector<vector<int>> list(3);

  InTraverse(root, list[0], list[1], list[2]);

  return list;
}
