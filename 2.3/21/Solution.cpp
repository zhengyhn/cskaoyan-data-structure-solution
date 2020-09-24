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
  int findKnthElement(ListNode *hair, int k) {
    ListNode *p = hair;
    for (int i = 0; i < k; ++i) {
      p = p->next;
      if (p == NULL) {
        return 0;
      }
    }
    ListNode *prev = hair;
    while (p != NULL) {
      prev = prev->next;
      p = p->next;
    }
    cout << prev->value << endl;
    return 1;
  }
};

int main() {
  Solution sln;
  int list1[] = {0xffff, 1, 2, 2, 3, 3};
  int len1 = sizeof(list1) / sizeof(int);
  ListNode *head1 = createList(list1, len1);
  cout << sln.findKnthElement(head1, 1) << endl;
  cout << sln.findKnthElement(head1, 3) << endl;
  cout << sln.findKnthElement(head1, 6) << endl;

  return 0;
}