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
  ListNode *removeX(ListNode *head, int x) {
    if (head == NULL) {
      return head;
    }
    if (head->value == x) {
      ListNode *p = head;
      head = removeX(head->next, x);
      delete p;
      return head;
    } else {
      head->next = removeX(head->next, x);
      return head;
    }
  }
};

int main() {
  Solution sln;
  int list[] = {2, 2, 3, 2, 3};
  int len = sizeof(list) / sizeof(int);
  ListNode *head = createList(list, len);
  ListNode *root = sln.removeX(head, 2);
  while (root != NULL) {
    cout << root->value << " ";
    root = root->next;
  }
  return 0;
}