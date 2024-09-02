#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
  int data;
  Node *next, *prev;
  Node() : data(0), next(nullptr), prev(nullptr) {}
  Node(int x) : data(x), next(nullptr), prev(nullptr) {}
  Node(int x, Node *next, Node *prev) : data(x), next(next), prev(prev) {}
};

void addAtEnd(Node *head, int data) {
  Node *temp = head;
  while (temp->next != nullptr)
    temp = temp->next;

  Node *newNode = new Node(data);
  temp->next = newNode;
  newNode->prev = temp;
}

Node *constructDLL(vector<int> &arr) {

  Node *head = new Node(arr[0]);
  for (int i = 1; i < arr.size(); i++) {
    addAtEnd(head, arr[i]);
  }

  return head;
}

Node *deleteLastNode(Node *head) {

  if (head == nullptr || head->next == nullptr)
    return nullptr;

  Node *temp = head;

  while (temp->next != nullptr) {
    temp = temp->next;
  }

  Node *nodeBefore = temp->prev;
  nodeBefore->next = nullptr;
  temp->prev = nullptr;

  delete temp;

  return head;
}

int main() {
  vector<int> v = {1, 2, 3, 4, 5};
  Node *head = constructDLL(v);
  for (Node *curr = head; curr != nullptr; curr = curr->next) {
    cout << " Node :: " << curr << " || Data :: " << curr->data
         << " | Next :: " << curr->next << " || Prev :: " << curr->prev
         << " ||\n";
  }
  return 0;
}
