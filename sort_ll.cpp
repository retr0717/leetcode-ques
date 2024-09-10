
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

Node *findMiddle(Node *head) {
  Node *tortoise = head;
  Node *hare = head->next;

  while (hare != nullptr && hare->next != nullptr) {
    hare = hare->next->next;
    tortoise = tortoise->next;
  }

  return tortoise;
}

Node *merge(Node *left, Node *right) {
  Node *dummyNode = new Node(-1);
  Node *temp = dummyNode;

  while (left != nullptr && right != nullptr) {
    if (left->data <= right->data) {
      temp->next = left;
      left = left->next;
    } else {
      temp->next = right;
      right = right->next;
    }

    temp = temp->next;
  }

  if (left != nullptr) {
    temp->next = left;
  } else {
    temp->next = right;
  }

  return dummyNode->next;
}

Node *sortLL(Node *head) {
  if (head == nullptr || head->next == nullptr)
    return head;

  Node *middle = findMiddle(head);

  // divide list to two.
  Node *right = middle->next;
  middle->next = nullptr;
  Node *left = head;

  left = sortLL(left);
  right = sortLL(right);

  return merge(left, right);
}
