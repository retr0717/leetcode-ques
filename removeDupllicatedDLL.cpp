#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node *prev;
  Node() {
    next = NULL;
    prev = NULL;
  }
  Node(int data) {
    this->data = data;
    next = NULL;
    prev = NULL;
  }
  Node(int data, Node *next, Node *prev) {
    this->data = data;
    this->next = next;
    this->prev = prev;
  }
};

Node *removeDuplicates(Node *head) {
  Node *temp = head;
  while (temp != nullptr && temp->next != nullptr) {
    Node *nextNode = temp->next;
    while (nextNode != nullptr && nextNode->data == temp->data) {
      nextNode = nextNode->next;
    }

    temp->next = nextNode;
    if (nextNode != nullptr)
      nextNode->prev = temp;
    temp = temp->next;
  }

  return head;
}
