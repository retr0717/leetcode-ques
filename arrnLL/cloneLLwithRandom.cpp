class Node {
public:
  int data;
  Node *next;
  Node *random;
  Node() : data(0), next(nullptr), random(nullptr){};
  Node(int x) : data(x), next(nullptr), random(nullptr) {}
  Node(int x, Node *next, Node *random) : data(x), next(next), random(random) {}
};

void insertCopyInBetween(Node *head) {
  Node *temp = head;
  while (temp != nullptr) {
    Node *nextElement = temp->next;
    Node *copy = new Node(temp->data);

    copy->next = nextElement;

    temp->next = copy;

    temp = nextElement;
  }
}

void connectRandomPointers(Node *head) {
  Node *temp = head;
  while (temp != nullptr) {
    Node *copyNode = temp->next;

    if (temp->random) {
      copyNode->random = temp->random->next;
    } else {
      copyNode->random = nullptr;
    }

    temp = temp->next->next;
  }
}

Node *getDeepCopyList(Node *head) {
  Node *temp = head;
  Node *dummyNode = new Node(-1);
  Node *res = dummyNode;

  while (temp != nullptr) {
    res->next = temp->next;
    res = res->next;

    temp->next = temp->next->next;
    temp = temp->next;
  }

  return dummyNode->next;
}

Node *cloneLL(Node *head) {

  if (!head)
    return nullptr;

  insertCopyInBetween(head);
  connectRandomPointers(head);

  return getDeepCopyList(head);
}
