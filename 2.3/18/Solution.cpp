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
  p->next = head;
  return head;
}

class Solution {
 public:
  void connect(ListNode *head1, ListNode *head2) {
    ListNode *p = head1;
    while (p->next != head1) {
      p = p->next;
    }
    p->next = head2;
    p = head2;
    while (p->next != head2) {
      p = p->next;
    }
    p->next = head1;
  }
};

int main() {
  Solution sln;
  int list1[] = {1, 2, 3};
  int len1 = sizeof(list1) / sizeof(int);
  ListNode *head1 = createList(list1, len1);
  int list2[] = {3, 2, 1};
  int len2 = sizeof(list2) / sizeof(int);
  ListNode *head2 = createList(list2, len2);
  sln.connect(head1, head2);
  for (ListNode *p = head1; p != NULL; p = p->next) {
    cout << p->value << endl;
    if (p->next == head1) {
      break;
    }
  }

  return 0;
}