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
  void sortOutput(ListNode *hair) {
    ListNode *p, *prev, *minCur, *minPrev;

    while (hair->next != hair) {
      minCur = p = hair->next;
      minPrev = prev = hair;
      prev = prev->next;
      p = prev->next;
      while (p != hair) {
        if (p->value < minCur->value) {
          minCur = p;
          minPrev = prev;
        }
        prev = prev->next;
        p = prev->next;
      }
      cout << minCur->value << " ";
      minPrev->next = minCur->next;
      delete minCur;
    }
    cout << endl;
    delete hair;
  }
};

int main() {
  Solution sln;
  int list1[] = {0xffff, 2, 1, 3, 0, 4};
  int len1 = sizeof(list1) / sizeof(int);
  ListNode *head1 = createList(list1, len1);
  sln.sortOutput(head1);

  return 0;
}