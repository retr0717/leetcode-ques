#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
  struct node {
    int key;
    int value;
    struct node *back = NULL;
    struct node *next = NULL;
  } *head, *tail;

  map<int, struct node *> mpp;
  int capacity;

  LRUCache(int _capacity) {
    capacity = _capacity;

    head = new node();
    tail = new node();
    head->next = tail;
    tail->back = head;
  }

  void insertAtHead(struct node *nodeAddr) {
    nodeAddr->back = head;
    nodeAddr->next = head->next;

    head->next->back = nodeAddr;
    head->next = nodeAddr;
  }

  void deleteNode(struct node *nodeAddr) {
    struct node *prevNode = nodeAddr->back;
    struct node *nextNode = nodeAddr->next;

    prevNode->next = nextNode;
    nextNode->back = prevNode;
  }

  int get(int key) {
    if (mpp.find(key) == mpp.end())
      return -1;

    struct node *nodeAddr = mpp[key];

    deleteNode(nodeAddr);
    insertAtHead(nodeAddr);

    return nodeAddr->value;
  }

  void put(int key, int value) {
    if (mpp.find(key) != mpp.end()) {

      struct node *nodeAddr = mpp[key];
      nodeAddr->value = value;

      deleteNode(nodeAddr);
      insertAtHead(nodeAddr);
    } else {
      if (mpp.size() == capacity) {

        struct node *nodeAddr = tail->back;
        mpp.erase(nodeAddr->key);
        deleteNode(nodeAddr);
        delete nodeAddr;
      }

      struct node *newNode = new node();
      newNode->key = key;
      newNode->value = value;
      mpp[key] = newNode;
      insertAtHead(newNode);
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
