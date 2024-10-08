#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node() {
    this->data = 0;
    this->next = NULL;
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

Node *addTwoNumbers(Node *num1, Node *num2) {
  Node *dummyNode = new Node();
  Node *temp = dummyNode;
  int carry = 0;

  while (num1 != nullptr || num2 != nullptr || carry) {
    int sum = 0;
    if (num1 != nullptr) {
      sum += num1->data;
      num1 = num1->next;
    }

    if (num2 != nullptr) {
      sum += num2->data;
      num2 = num2->next;
    }

    sum += carry;
    carry = sum / 10;
    Node *newNode = new Node(sum % 10);
    temp->next = newNode;
    temp = temp->next;
  }

  return dummyNode->next;
}
