#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }

  Node(int data, Node *next) {
    this->data = data;
    this->next = next;
  }
};

int main() {
  vector<int> v = {1, 2, 3, 4, 5};
  Node *head = new Node(v[0]);
  Node *temp = head;
  for (int i = 1; i < v.size(); i++) {
    temp->next = new Node(v[i]);
    temp = temp->next;
  }

  for (Node *curr = head; curr != nullptr; curr = curr->next) {
    cout << " Node :: " << curr << " || Data :: " << curr->data
         << " | Next :: " << curr->next << " ||\n";
  }

  int val = 6;
  Node *newNode = new Node(val);
  newNode->next = head;
  head = newNode;

  cout << "After adding new node at the beginning\n";
  for (Node *curr = head; curr != nullptr; curr = curr->next) {
    cout << " Node :: " << curr << " || Data :: " << curr->data
         << " | Next :: " << curr->next << " ||\n";
  }
  return 0;
}
