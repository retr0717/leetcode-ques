#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node() {
    this->data = 0;
    next = NULL;
  }
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
  Node(int data, Node *next) {
    this->data = data;
    this->next = next;
  }
};

Node *deleteMiddle(Node *head) {

  if (head->next == nullptr || head == nullptr)
    return nullptr;

  Node *tortoise = head;
  Node *hare = head->next->next;

  while (hare != nullptr && hare->next != nullptr) {
    tortoise = tortoise->next;
    hare = hare->next->next;
  }

  tortoise->next = tortoise->next->next;

  return head;
}
