#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node() : data(0), next(nullptr) {}
  Node(int x) : data(x), next(nullptr) {}
  Node(int x, Node *next) : data(x), next(next) {}
};

int findLength(Node *head) {
  int count = 0;
  while (head != nullptr) {
    count++;
    head = head->next;
  }

  return count;
}

Node *findKthNode(Node *node, int k) {
  k -= 1;

  while (node != nullptr && k > 0) {
    k -= 1;
    node = node->next;
  }

  return node;
}

Node *reverseLL(Node *head) {
  if (head == nullptr || head->next == nullptr)
    return head;

  Node *newHead = reverseLL(head->next);
  Node *front = head->next;
  front->next = head;
  head->next = nullptr;
  return newHead;
}

Node *kReverse(Node *head, int k) {

  Node *temp = head;
  Node *prevLast = nullptr;

  while (temp != nullptr) {
    Node *kthNode = findKthNode(temp, k);

    if (kthNode == nullptr) {
      if (prevLast) {
        prevLast->next = temp;
      }
      break;
    }

    Node *nextNode = kthNode->next;
    kthNode->next = nullptr;
    reverseLL(temp);

    if (temp == head) {
      head = kthNode;
    } else {
      prevLast->next = kthNode;
    }

    prevLast = temp;
    temp = nextNode;
  }

  return head;
}
