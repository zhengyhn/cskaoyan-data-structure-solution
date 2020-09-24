#include <iostream>

using namespace std;

struct ListNode {
  char data;
  ListNode *next;
  ListNode(char x) : data(x), next(NULL) {}
};
ListNode* createList(string s) {
  ListNode *head = new ListNode('\0');
  ListNode *p = head;
  for (int i = 0; i < s.size(); ++i) {
    p->next = new ListNode(s[i]);
    p = p->next; 
  }
  return head;
}

class Solution {
 public:
  ListNode *findCommonNode(ListNode *str1, ListNode *str2) {
    int len1 = 0;
    int len2 = 0;
    ListNode *p = str1;
    while (p != NULL) {
      ++len1;
      p = p->next;
    }
    p = str2;
    while (p != NULL) {
      ++len2;
      p = p->next;
    }
    ListNode *longer = len1 > len2 ? str1 : str2;
    ListNode *shorter = len1 <= len2 ? str1 : str2;
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
  ListNode *str1 = createList("load");
  ListNode *str2 = createList("be");
  ListNode *str3 = createList("ing");
  ListNode *p = str1;
  while (p->next != NULL) {
    p = p->next;
  }
  p->next = str3->next;
  p = str2;
  while (p->next != NULL) {
    p = p->next;
  }
  p->next = str3->next;

  ListNode *ret = sln.findCommonNode(str1, str2);
  cout << ret->data << endl;

  return 0;
}