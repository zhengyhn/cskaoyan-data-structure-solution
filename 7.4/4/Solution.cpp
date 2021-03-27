#include <iostream>

using namespace std;

struct LinkedNode {
  int value;
  struct LinkedNode *next;
  LinkedNode(int v, LinkedNode *n): value(v), next(n) {}
};

class Solution {
 public:
  LinkedNode *selectSort(LinkedNode *head) {
    LinkedNode *dummy = new LinkedNode(0, head);
    LinkedNode *hair = new LinkedNode(0, NULL);
    LinkedNode *p = head;
    LinkedNode *prev = dummy;
    while (p != NULL) {
      int max = p->value;
      LinkedNode *pSelect = p;
      LinkedNode *prevSelect = prev;
      while (p != NULL) {
        if (p->value > max) {
          max = p->value;
          pSelect = p;
          prevSelect = prev;
        }
        prev = p;
        p = p->next;
      }
      if (pSelect) {
        prevSelect->next = pSelect->next;
        pSelect->next = hair->next;
        p = dummy->next;
        prev = dummy;
        hair->next = pSelect;
      }
    }
    return hair->next;
  }
};

int main() {
  Solution sln;
  int arr[8] = {5, 2, 3, 1, 6, 7, 10, 8};
  LinkedNode *head = new LinkedNode(arr[0], NULL);
  LinkedNode *p = head;
  for (int i = 1; i < 8; ++i) {
    p->next = new LinkedNode(arr[i], NULL);
    p = p->next;
  }
  p = sln.selectSort(head);
  while (p) {
    cout << p->value << endl;
    p = p->next;
  }

  return 0;
}