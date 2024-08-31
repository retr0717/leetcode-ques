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

int findLength(Node *head) {
  int len = 0;
  Node *curr = head;
  while (curr != nullptr) {
    len++;
    curr = curr->next;
  }

  return len;
}

bool searchList(Node *head, int val) {
  Node *curr = head;
  while (curr != nullptr) {
    if (curr->data == val)
      return true;
    curr = curr->next;
  }
  return false;
}

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

  int len = findLength(head);
  cout << "Length of the linked list is : " << len << endl;

  int val = 6;
  Node *newNode = new Node(val);
  newNode->next = head;
  head = newNode;

  cout << "After adding new node at the beginning\n";
  for (Node *curr = head; curr != nullptr; curr = curr->next) {
    cout << " Node :: " << curr << " || Data :: " << curr->data
         << " | Next :: " << curr->next << " ||\n";
  }

  len = findLength(head);
  cout << "Length of the linked list is : " << len << endl;

  bool result = searchList(head, 4);
  cout << "Search result for 4 is : " << result << endl;

  result = searchList(head, 7);
  cout << "Search result for 7 is : " << result << endl;

  return 0;
}
