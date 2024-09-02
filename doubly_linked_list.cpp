#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node *prev;

  Node(int data) {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

void addAtEnd(Node *head, int data) {
  Node *newNode = new Node(data);
  Node *curr = head;
  while (curr->next != nullptr) {
    curr = curr->next;
  }
  curr->next = newNode;
  newNode->prev = curr;
}

int main() {
  Node *head = new Node(1);

  addAtEnd(head, 2);
  addAtEnd(head, 3);
  addAtEnd(head, 4);

  Node *temp = head;
  while (temp != nullptr) {
    cout << "addr : " << temp << " | prev : " << temp->prev
         << " | data : " << temp->data << " | next : " << temp->next << endl;
    ;
    temp = temp->next;
  }

  return 0;
}
