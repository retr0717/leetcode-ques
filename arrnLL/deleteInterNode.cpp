#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  void deleteNode(ListNode *node) {
    if (node == nullptr || node->next == nullptr)
      return;

    node->val = node->next->val;
    ListNode *nextNode = node->next;
    node->next = node->next->next;
    delete nextNode;
  }
};

int main() {
  vector<int> v = {1, 2, 3, 4, 5};
  ListNode *head = new ListNode(v[0]);
  ListNode *temp = head;
  for (int i = 1; i < v.size(); i++) {
    temp->next = new ListNode(v[i]);
    temp = temp->next;
  }
  for (ListNode *curr = head; curr != nullptr; curr = curr->next) {
    cout << " Node :: " << curr << " || Data :: " << curr->val
         << " | Next :: " << curr->next << " ||\n";
  }
  Solution s;
  ListNode *node = head->next;
  s.deleteNode(node);
  cout << "After deleting node\n";
  for (ListNode *curr = head; curr != nullptr; curr = curr->next) {
    cout << " Node :: " << curr << " || Data :: " << curr->val
         << " | Next :: " << curr->next << " ||\n";
  }
  return 0;
}
