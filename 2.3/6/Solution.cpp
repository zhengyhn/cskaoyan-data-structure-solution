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
    ListNode *prev = p;
    p = p->next;
    while (p != NULL) {
      ListNode *tempPrev = hair;
      ListNode *temp = hair->next;
      while (p->value > temp->value && temp != p) {
        tempPrev = temp;
        temp = tempPrev->next;
      }
      if (temp != p) {
        prev->next = p->next;
        tempPrev->next = p;
        p->next = temp;
        p = prev->next;
      } else {
        prev = p;
        p = prev->next;
      }
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