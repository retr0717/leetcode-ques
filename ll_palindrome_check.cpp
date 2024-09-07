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

Node *reverseLinkedListRecursion(Node *head) {
  if (head == nullptr || head->next == nullptr)
    return head;
  Node *newHead = reverseLinkedListRecursion(head->next);
  Node *front = head->next;
  front->next = head;
  head->next = nullptr;
  return newHead;
}

Node *findMiddle(Node *head) {
  Node *hare = head;
  Node *tortoise = head;

  while (hare != nullptr && hare->next != nullptr) {
    tortoise = tortoise->next;
    hare = hare->next->next;
  }

  return tortoise;
}

bool isPalindrome(Node *head) {
  Node *middle = findMiddle(head);
  Node *newHead = reverseLinkedListRecursion(middle);

  while (head != middle) {
    if (head->data != newHead->data)
      return false;

    head = head->next;
    newHead = newHead->next;
  }

  return true;
}
