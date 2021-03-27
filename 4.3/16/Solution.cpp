#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
  int value;
  TreeNode *left;
  TreeNode *right;

 public:
  TreeNode(int val) : value(val) {}
};

class Solution {
 public:
  TreeNode *getLeafLink(TreeNode *root) {
    stack<TreeNode *> st;
    st.push(root);
    TreeNode *head = NULL;
    TreeNode *p;
    while (!st.empty()) {
      TreeNode *top = st.top();
      st.pop();
      if (!top->left && !top->right) {
        if (!head) {
          head = top;
          p = top;
        } else {
          p->right = top;
          p = top;
        }
      }
      if (top->right) {
        st.push(top->right);
      }
      if (top->left) {
        st.push(top->left);
      } 
    }
    return head;
  }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  TreeNode *head = sln.getLeafLink(root);
  TreeNode *p = head;
  while (p) {
    cout << p->value << endl;
    p = p->right;
  }
  return 0;
}