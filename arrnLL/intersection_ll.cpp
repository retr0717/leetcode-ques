
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

Node *findIntersection(Node *firstHead, Node *secondHead) {
  unordered_set<Node *> st;

  while (firstHead != nullptr) {
    st.insert(firstHead);
    firstHead = firstHead->next;
  }

  while (secondHead != nullptr) {
    if (st.find(secondHead) != st.end())
      return secondHead;
    secondHead = secondHead->next;
  }

  return nullptr;
}
