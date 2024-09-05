#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};

bool detectCycle(Node *head) {
  Node *hare = head;
  Node *tortoise = head;

  while (hare != nullptr && hare->next != nullptr) {

    hare = hare->next->next;
    tortoise = tortoise->next;

    if (hare == tortoise)
      return true;
  }

  return false;
}

void append(Node **head, int data) {
  struct Node *new_node;
  Node *last = *head;
  new_node->data = data;
  new_node->next = nullptr;
  if (*head == nullptr) {
    *head = new_node;
    return;
  }
  while (last->next != nullptr) {
    last = last->next;
  }
  last->next = new_node;
}

int main(void) {
  // create a linked list with detectCycle
  struct Node *head;
  append(&head, 1);
  append(&head, 2);
  append(&head, 3);
  append(&head, 4);

  bool result = detectCycle(head);
  if (result)
    cout << "Cycle detected in the linked list" << endl;
  else
    cout << "No cycle detected in the linked list" << endl;
}
