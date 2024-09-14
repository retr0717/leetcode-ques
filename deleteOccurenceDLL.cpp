#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *prev;
  Node *next;
  Node() {
    this->data = 0;
    this->prev = NULL;
    this->next = NULL;
  }
  Node(int data) {
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
  }
  Node(int data, Node *next, Node *prev) {
    this->data = data;
    this->prev = prev;
    this->next = next;
  }
};

Node *deleteAllOccurrences(Node *head, int k) {

  Node *temp = head;

  while (temp != nullptr) {
    if (temp->data == k) {
      if (temp == head) {
        head = temp->next;
      }

      Node *nextNode = temp->next;
      Node *prevNode = temp->prev;

      if (prevNode != nullptr)
        prevNode->next = nextNode;
      if (nextNode != nullptr)
        nextNode->prev = prevNode;

      free(temp);
      temp = nextNode;
    } else
      temp = temp->next;
  }

  return head;
}
