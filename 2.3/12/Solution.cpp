#include <iostream>

using namespace std;

struct ListNode {
  int value;
  ListNode *next;
  ListNode(int x) : value(x), next(NULL) {}
};
ListNode* createList(int list[], int len) {
  ListNode *head = new ListNode(list[0]);
  ListNode *p = head;
  for (int i = 1; i < len; ++i) {
    p->next = new ListNode(list[i]);
    p = p->next; 
  }
  return head;
}

class Solution {
 public:
  void removeDuplicate(ListNode *head) {
    ListNode *prev = head;
    ListNode *p = prev->next;
    while (p != NULL) {
      if (p->value == prev->value) {
        prev->next = p->next;
        delete p;
        p = prev->next;
      } else {
        prev = p;
        p = prev->next;
      }
    }
  }
};

int main() {
  Solution sln;
  int list[] = {1, 2, 2, 3, 3};
  int len = sizeof(list) / sizeof(int);
  ListNode *head = createList(list, len);
  sln.removeDuplicate(head);
  ListNode *p = head;
  while (p != NULL) {
    cout << p->value << endl;
    p = p->next;
  }

  return 0;
}