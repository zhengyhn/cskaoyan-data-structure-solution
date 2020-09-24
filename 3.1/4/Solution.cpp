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
  bool isSymmetric(ListNode *head) {
    if (head == NULL) {
      return true;
    }
    ListNode *dummy = new ListNode(0);
    ListNode *p1 = head;
    int num = 0;
    while (p1 != NULL) {
      ListNode *item = new ListNode(p1->value);
      item->next = dummy->next;
      dummy->next = item;
      p1 = p1->next;
      ++num;
    }
    p1 = head;
    ListNode *p2 = dummy->next;
    for (int i = 0; i < num; ++i) {
      if (p1->value != p2->value) {
        return false;
      }
      p1 = p1->next;
      p2 = p2->next;
    }
    return true;
  }
};

int main() {
  Solution sln;
  int list[] = {2, 2, 3, 2, 2};
  int len = sizeof(list) / sizeof(int);
  ListNode *head = createList(list, len);
  cout << sln.isSymmetric(head) << endl;
  return 0;
}