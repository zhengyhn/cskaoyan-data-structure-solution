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
  void removeDuplicate(ListNode *hair, int n) {
    int *set = new int[n + 1];
    for (int i = 0; i <= n; ++i) {
      set[i] = 0;
    }
    ListNode *prev = hair;
    ListNode *p = prev->next;
    while (p != NULL) {
      int value = abs(p->value);
      if (set[value] == 0) {
        set[value] = 1;
        prev = prev->next;
      } else {
        prev->next = p->next;
        delete p;
      }
      p = prev->next;
    }
  }
};

int main() {
  Solution sln;
  int list1[] = {0xffff, 1, 2, -2, 3, 2};
  int len1 = sizeof(list1) / sizeof(int);
  ListNode *head1 = createList(list1, len1);
  sln.removeDuplicate(head1, 3);
  ListNode *p = head1->next;
  while (p != NULL) {
    cout << p->value << endl;
    p = p->next;
  }

  return 0;
}