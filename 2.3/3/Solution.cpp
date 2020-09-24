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
  void reverseOutput(ListNode *hair) {
    output(hair->next);
  }

  void output(ListNode *node) {
    if (node == NULL) {
      return;
    }
    output(node->next);
    cout << node->value << " ";
  }
};

int main() {
  Solution sln;
  int list[] = {0xffff, 2, 2, 3, 2, 3};
  int len = sizeof(list) / sizeof(int);
  ListNode *hair = createList(list, len);
  sln.reverseOutput(hair);

  return 0;
}