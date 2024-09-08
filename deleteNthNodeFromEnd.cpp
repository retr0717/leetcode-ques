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

Node *removeKthNode(Node *head, int K) {
  Node *temp = head;
  Node *prev = head;
  int i = 0;
  while (i < K) {
    temp = temp->next;
    i++;
  }

  if (temp == nullptr)
    return head->next;

  while (temp->next != nullptr) {
    temp = temp->next;
    prev = prev->next;
  }

  prev->next = prev->next->next;

  return head;
}
