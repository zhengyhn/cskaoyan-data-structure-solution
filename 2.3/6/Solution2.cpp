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
  void sort(ListNode *hair) {
    ListNode *p = hair->next;
    if (p->next == NULL) {
      return;
    }
    ListNode *next = p->next;
    p->next = NULL;
    p = next;
    ListNode *prev = hair;
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
  }
};

int main() {
  Solution sln;
  int list[] = {0xffff, 1, 2, 2, 3, 2, 3};
  int len = sizeof(list) / sizeof(int);
  ListNode *hair = createList(list, len);
  sln.sort(hair);
  ListNode *root = hair->next;
  while (root != NULL) {
    cout << root->value << " ";
    root = root->next;
  }
  return 0;
}