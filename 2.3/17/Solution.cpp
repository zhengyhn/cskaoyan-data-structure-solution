#include <iostream>

using namespace std;

struct ListNode {
  int value;
  ListNode *prev;
  ListNode *next;
  ListNode(int x) : value(x), next(NULL) {}
};
ListNode* createList(int list[], int len) {
  ListNode *head = new ListNode(list[0]);
  ListNode *p = head;
  for (int i = 1; i < len; ++i) {
    p->next = new ListNode(list[i]);
    p->next->prev = p;
    p = p->next; 
  }
  p->next = head;
  head->prev = p;
  return head;
}

class Solution {
 public:
  bool isSymmetry(ListNode *hair) {
    ListNode *p1 = hair->next;
    ListNode *p2 = hair->prev;
    while (p1 != p2) {
      if (p1->value != p2->value) {
        return false;
      }
      p1 = p1->next;
      p2 = p2->prev;
    }
    return true;
  }
};

int main() {
  Solution sln;
  int list1[] = {0xffff, 1, 2, 3, 3, 2, 1, 2};
  int len1 = sizeof(list1) / sizeof(int);
  ListNode *head1 = createList(list1, len1);
  cout << sln.isSymmetry(head1) << endl;

  return 0;
}