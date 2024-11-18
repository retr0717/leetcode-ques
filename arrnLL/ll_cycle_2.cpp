#include <iostream>
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

Node *firstNode(Node *head) {
  Node *hare = head;
  Node *tortoise = head;
  while (hare != nullptr && hare->next != nullptr) {
    hare = hare->next->next;
    tortoise = tortoise->next;

    if (tortoise == hare) {
      tortoise = head;

      while (tortoise != hare) {
        tortoise = tortoise->next;
        hare = hare->next;
      }

      return hare;
    }
  }

  return nullptr;
}

int main() {
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);

  return 0;
}
