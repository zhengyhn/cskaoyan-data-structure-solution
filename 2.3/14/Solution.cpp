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
  ListNode *getSameElements(ListNode *hair1, ListNode *hair2) {
    ListNode *p1 = hair1->next;
    ListNode *p2 = hair2->next;
    ListNode *dummy = new ListNode(0);
    ListNode *p = dummy;
    while (p1 != NULL && p2 != NULL) {
      if (p1->value == p2->value) {
        p->next = new ListNode(p1->value);
        p = p->next;
        p1 = p1->next;
        p2 = p2->next;
      } else if (p1->value < p2->value) {
        p1 = p1->next;
      } else {
        p2 = p2->next;
      }
    }
    return dummy->next;
  }
};

int main() {
  Solution sln;
  int list1[] = {0xffff, 1, 2, 2, 3, 3};
  int len1 = sizeof(list1) / sizeof(int);
  ListNode *head1 = createList(list1, len1);
  int list2[] = {0xffff, 2, 3, 4};
  int len2 = sizeof(list2) / sizeof(int);
  ListNode *head2 = createList(list2, len2);
  ListNode *ret = sln.getSameElements(head1, head2);
  ListNode *p = ret;
  while (p != NULL) {
    cout << p->value << endl;
    p = p->next;
  }

  return 0;
}