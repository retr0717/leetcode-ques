#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node() : data(0), next(nullptr){};
  Node(int x) : data(x), next(nullptr) {}
  Node(int x, Node *next) : data(x), next(next) {}
};

Node *segregateEvenOdd(Node *head) {
  Node *evenList = new Node(0);
  Node *evenHead = evenList;
  Node *oddList = new Node(0);
  Node *oddHead = oddList;

  while (head != nullptr) {
    Node *newNode = new Node(head->data);
    if (head->data % 2 == 0) {
      evenList->next = newNode;
      evenList = evenList->next;
    } else {
      oddList->next = newNode;
      oddList = oddList->next;
    }

    head = head->next;
  }

  evenList->next = oddHead->next;

  return evenHead->next;
}
