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
  Node *hare = head;
  Node *prev = head;

  while (hare != nullptr && hare->next != nullptr) {
    prev = tortoise;
    tortoise = tortoise->next;
    hare = hare->next->next;
  }

  prev->next = tortoise->next;

  return head;
}
