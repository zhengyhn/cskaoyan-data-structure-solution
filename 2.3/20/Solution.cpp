#include <iostream>

using namespace std;

struct ListNode {
  int value;
  int freq;
  ListNode *prev;
  ListNode *next;
  ListNode(int x) : value(x), freq(0), next(NULL) {}
};

ListNode* createList(int list[], int len) {
  ListNode *head = new ListNode(list[0]);
  ListNode *p = head;
  for (int i = 1; i < len; ++i) {
    p->next = new ListNode(list[i]);
    p->next->prev = p;
    p = p->next; 
  }
  return head;
}

class Solution {
 public:
  ListNode *locate(ListNode *hair, int x) {
    ListNode *prev = hair;
    ListNode *p = hair->next;
    ListNode *next;
    while (p != NULL) {
      if (p->value == x) {
        p->freq += 1;
        prev->next = p->next;
        if (prev->next != NULL) {
          prev->next->prev = prev;
        }
        prev = hair;
        next = prev->next;
        while (next != NULL && next->freq > p->freq) {
          prev = prev->next;
          next = prev->next;
        }
        prev->next = p;
        p->prev = prev;
        p->next = next;
        if (next != NULL) {
          next->prev = p;
        }
        return p;
      }
      prev = prev->next;
      p = prev->next;
    }
    return NULL;
  }
};

int main() {
  Solution sln;
  int list1[] = {0xffff, 2, 1, 3, 0, 4};
  int len1 = sizeof(list1) / sizeof(int);
  ListNode *head1 = createList(list1, len1);
  sln.locate(head1, 3);
  for (ListNode *p = head1->next; p != NULL; p = p->next) {
    cout << p->value << " ";
  }
  cout << endl;
  sln.locate(head1, 4);
  for (ListNode *p = head1->next; p != NULL; p = p->next) {
    cout << p->value << " ";
  }
  cout << endl;
  sln.locate(head1, 3);
  for (ListNode *p = head1->next; p != NULL; p = p->next) {
    cout << p->value << " ";
  }
  cout << endl;

  return 0;
}