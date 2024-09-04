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

Node *reverseLinkedList(Node *head) {
  Node *prev = nullptr;
  Node *temp = head;

  while (temp != nullptr) {
    Node *next = temp->next;
    temp->next = prev;
    prev = temp;
    temp = next;
  }

  return prev;
}
