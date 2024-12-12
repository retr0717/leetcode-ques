#include <bits/stdc++.h>
using namespace std;

class LFUCache {
public:
  struct Node {
    int key;
    int value;
    int freq;
    struct Node *prev;
    struct Node *next;

    Node(int k, int v) : key(k), value(v), freq(1), prev(NULL), next(NULL) {}
  };

  map<int, struct Node *> keyMap;
  map<int, list<Node *>> freqMap;
  int capacity;
  int minFreq;
  int size;

  LFUCache(int _capacity) {
    capacity = _capacity;
    size = 0;
    minFreq = 0;
  }

  int get(int key) {

    if (keyMap.find(key) == keyMap.end())
      return -1;

    Node *currNode = keyMap[key];

    freqMap[currNode->freq].remove(currNode);
    if (freqMap[currNode->freq].empty() && currNode->freq == minFreq)
      minFreq++;

    currNode->freq++;

    freqMap[currNode->freq].push_back(currNode);

    return currNode->value;
  }

  void put(int key, int value) {
    if (capacity == 0)
      return;

    // if the key already exists.
    if (keyMap.find(key) != keyMap.end()) {
      Node *currNode = keyMap[key];
      currNode->value = value;
      get(key);
      return;
    }

    // if the capacity is full.
    if (size == capacity) {
      Node *rNode = freqMap[minFreq].front();
      freqMap[minFreq].pop_front();
      keyMap.erase(rNode->key);
      delete rNode;
      size--;
    }

    // add the new node.
    struct Node *newNode = new Node(key, value);
    keyMap[key] = newNode;
    freqMap[1].push_back(newNode);
    minFreq = 1;
    size++;
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
