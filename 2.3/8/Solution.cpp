#include <iostream>

using namespace std;

struct ListNode {
  int value;
  ListNode *next;
  ListNode(int x) : value(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* findCommonNode(ListNode *head1, ListNode *head2) {
    int len1 = 0;
    int len2 = 0;
    ListNode *p = head1;
    while (p != NULL) {
      ++len1;
      p = p->next;
    }
    p = head2;
    while (p != NULL) {
      ++len2;
      p = p->next;
    }
    ListNode *shorter;
    ListNode *longer;
    if (len1 < len2) {
      shorter = head1;
      longer = head2;
    } else {
      shorter = head2;
      longer = head1;
    }
    for (int i = 0; i < abs(len1 - len2); ++i) {
      longer = longer->next;
    }
    while (longer != shorter) {
      longer = longer->next;
      shorter = shorter->next;
    }
    return longer;
  }
};

int main() {
  Solution sln;
  ListNode *head1 = new ListNode(1);
  head1->next = new ListNode(2);
  head1->next->next = new ListNode(3);
  head1->next->next->next = new ListNode(4);

  ListNode *head2 = new ListNode(2);
  head2->next = head1->next->next;

  ListNode *ret = sln.findCommonNode(head1, head2);
  cout << ret->value << endl;
  
  return 0;
}