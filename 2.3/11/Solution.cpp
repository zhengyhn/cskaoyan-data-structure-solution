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
  ListNode *split(ListNode *hair) {
    ListNode *dummy = new ListNode(0);
    ListNode *p = hair->next;
    hair->next = NULL;
    ListNode *p1 = hair;
    ListNode *next;
    int i = 0;
    while (p != NULL) {
      next = p->next;
      if (i % 2 == 0) {
        p1->next = p;
        p1 = p1->next;
      } else {
        p->next = dummy->next;
        dummy->next = p;
      }
      p = next;
      ++i;
    }
    p1->next = NULL;

    return dummy;
  }
};

int main() {
  Solution sln;
  int list[] = {0xffff, 1, 2, 2, 3, 2, 3};
  int len = sizeof(list) / sizeof(int);
  ListNode *hair = createList(list, len);
  ListNode *another = sln.split(hair);
  ListNode *p = hair->next;
  while (p != NULL) {
    cout << p->value << endl;
    p = p->next;
  }
  cout << endl;
  p = another->next;
  while (p != NULL) {
    cout << p->value << endl;
    p = p->next;
  }

  return 0;
}