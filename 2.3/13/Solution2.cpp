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
  ListNode *merge(ListNode *head1, ListNode *head2) {
    ListNode *hair = new ListNode(0);
    ListNode *p1 = head1;
    ListNode *p2 = head2;
    ListNode *next;
    while (p1 != NULL && p2 != NULL) {
      if (p1->value < p2->value) {
        next = p1->next;
        p1->next = hair->next;
        hair->next = p1;
        p1 = next;
      } else {
        next = p2->next;
        p2->next = hair->next;
        hair->next = p2;
        p2 = next;
      }
    }
    if (p1 == NULL) {
      p1 = p2;
    }
    while (p1 != NULL) {
      next = p1->next;
      p1->next = hair->next;
      hair->next = p1;
      p1 = next;
    }
    return hair->next;
  }
};

int main() {
  Solution sln;
  int list1[] = {1, 2, 2, 3, 3};
  int len1 = sizeof(list1) / sizeof(int);
  ListNode *head1 = createList(list1, len1);
  int list2[] = {2, 3, 4};
  int len2 = sizeof(list2) / sizeof(int);
  ListNode *head2 = createList(list2, len2);
  ListNode *ret = sln.merge(head1, head2);
  ListNode *p = ret;
  while (p != NULL) {
    cout << p->value << endl;
    p = p->next;
  }

  return 0;
}