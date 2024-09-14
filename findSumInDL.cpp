#include <bits/stdc++.h>

using namespace std;

class Node {
public:
  int data;
  Node *prev;
  Node *next;
  Node() {

    this->data = 0;
    this->prev = NULL;
    this->next = NULL;
  }
  Node(int data) {
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
  }
  Node(int data, Node *next, Node *prev) {
    this->data = data;
    this->prev = prev;
    this->next = next;
  }
};

Node *findLast(Node *head) {
  Node *temp = head;
  while (temp->next != nullptr)
    temp = temp->next;

  return temp;
}

vector<pair<int, int>> findPairs(Node *head, int k) {
  vector<pair<int, int>> arr;
  Node *left = head;
  Node *right = findLast(head);

  while (left->data < right->data) {
    int sum = left->data + right->data;
    if (sum == k) {
      arr.push_back({left->data, right->data});
      left = left->next;
      right = right->prev;
    } else if (sum < k)
      left = left->next;
    else
      right = right->prev;
  }

  return arr;
}
