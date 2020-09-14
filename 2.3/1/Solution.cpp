#include <iostream>

using namespace std;

struct ListNode {
  int value;
  ListNode *next;
  ListNode(int x) : value(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *removeX(ListNode *head, int x) {
    if (head == NULL) {
      return head;
    }
    if (head->value == x) {
      return removeX(head->next, x);
    } else {
      head->next = removeX(head->next, x);
      return head;
    }
  }
};

int main() {
  Solution sln;
  ListNode *head = new ListNode(2);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  ListNode *root = sln.removeX(head, 2);
  while (root != NULL) {
    cout << root->value << " ";
    root = root->next;
  }
  return 0;
}