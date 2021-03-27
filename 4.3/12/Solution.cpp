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
  void printAncestorsByValue(TreeNode *root, int x) {
    stack<TreeNode *> st;
    TreeNode *p = root;
    TreeNode *recent = NULL;
    while (p || !st.empty()) {
      if (p) {
        st.push(p);
        p = p->left;
      } else {
        TreeNode *top = st.top();
        if (top->value == x) {
          st.pop();
          while (!st.empty()) {
            cout << st.top()->value << endl;
            st.pop();
          }
          return;
        }
        if (top->right && top->right != recent) {
          p = top->right;
        } else {
          recent = top;
          st.pop();
          p = NULL;
        }
      }
    }
  }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  sln.printAncestorsByValue(root, 4);
  sln.printAncestorsByValue(root, 5);
  sln.printAncestorsByValue(root, 3);
  sln.printAncestorsByValue(root, 2);

  return 0;
}