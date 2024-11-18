#include <iostream>

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

Node *findMiddle(Node *head) {
  Node *hare = head;
  Node *tortoise = head;

  while (hare != nullptr && hare->next != nullptr) {
    tortoise = tortoise->next;
    hare = hare->next->next;
  }

  return tortoise;
}
