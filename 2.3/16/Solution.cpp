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
  bool isSubList(ListNode *head1, ListNode *head2) {
    ListNode *p1 = head1;
    ListNode *p2 = head2;
    ListNode *p;
    while (p1 != NULL) {
      if (p1->value == p2->value) {
        p = p1->next;
        p2 = p2->next;
        while (p != NULL && p2 != NULL) {
          if (p->value != p2->value) {
            break;
          }
          p = p->next;
          p2 = p2->next;
        }
        if (p2 == NULL) {
          return true;
        }
        p2 = head2; 
      }
      p1 = p1->next;
    }
    return false;
  }
};

int main() {
  Solution sln;
  int list1[] = {1, 2, 3};
  int len1 = sizeof(list1) / sizeof(int);
  ListNode *head1 = createList(list1, len1);
  int list2[] = {2, 3, 4};
  int len2 = sizeof(list2) / sizeof(int);
  ListNode *head2 = createList(list2, len2);
  cout << sln.isSubList(head1, head2) << endl;

  return 0;
}