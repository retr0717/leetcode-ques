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

Node *findMiddle(Node *head) {
  Node *tortoise = head;
  Node *hare = head->next;

  while (hare != nullptr && hare->next != nullptr) {
    hare = hare->next->next;
    tortoise = tortoise->next;
  }

  return tortoise;
}

Node *merge(Node *left, Node *right) {
  Node *dummyNode = new Node(-1);
  Node *temp = dummyNode;

  while (left != nullptr && right != nullptr) {
    if (left->data <= right->data) {
      temp->next = left;
      left = left->next;
    } else {
      temp->next = right;
      right = right->next;
    }

    temp = temp->next;
  }

  if (left != nullptr) {
    temp->next = left;
  } else {
    temp->next = right;
  }

  return dummyNode->next;
}

Node *sortList(Node *head) {

  if (head == nullptr || head->next == nullptr)
    return head;

  Node *middle = findMiddle(head);

  Node *left = head;
  Node *right = middle->next;
  middle->next = nullptr;

  left = sortList(left);
  right = sortList(right);

  return merge(left, right);
}

int main() {
  Node *head = new Node(1);
  head->next = new Node(0);
  head->next->next = new Node(1);
  head->next->next->next = new Node(0);
  head->next->next->next->next = new Node(1);
  Node *sorted = sortList(head);
  while (sorted != nullptr) {
    cout << sorted->data << " ";
    sorted = sorted->next;
  }
  return 0;
}
