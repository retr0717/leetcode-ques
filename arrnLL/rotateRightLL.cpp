class Node {
public:
  int data;
  Node *next;
  Node() : data(0), next(nullptr) {}
  Node(int x) : data(x), next(nullptr) {}
  Node(int x, Node *next) : data(x), next(next) {}
};

Node *rotate(Node *head, int k) {
  if (head == nullptr || head->next == nullptr)
    return head;

  int length = 1;
  Node *temp = head;
  while (temp->next != nullptr) {
    length++;
    temp = temp->next;
  }

  temp->next = head;
  k = k % length;
  int end = length - k;
  while (end--) {
    temp = temp->next;
  }

  head = temp->next;
  temp->next = nullptr;

  return head;
}
