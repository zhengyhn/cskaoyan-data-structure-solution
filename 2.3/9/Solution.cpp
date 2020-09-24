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
  void sortOutput(ListNode *hair) {
    ListNode *p = hair->next;
    if (p == NULL) {
      return;
    }
    ListNode *next = p->next;
    p->next = NULL;
    ListNode *prev = hair;
    p = next;
    while (p != NULL) {
      next = p->next;
      prev = hair;
      while (prev->next != NULL && prev->next->value < p->value) {
        prev = prev->next;
      }
      p->next = prev->next;
      prev->next = p;
      p = next;
    }
    p = hair->next;
    while (p != NULL) {
      cout << p->value << " ";
      prev = p;
      p = p->next;
      delete prev;
    }
    delete hair;
  }
};

int main() {
  Solution sln;
  int list[] = {0xffff, 1, 2, 2, 3, 2, 3};
  int len = sizeof(list) / sizeof(int);
  ListNode *hair = createList(list, len);
  sln.sortOutput(hair);

  return 0;
}