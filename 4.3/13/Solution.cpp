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
  void ancestor(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode **r) {
    stack<TreeNode *> ancestors;
    stack<TreeNode *> st;
    TreeNode *temp = root;
    bool foundOne = false;
    TreeNode *recent;
    while (temp || !st.empty()) {
      if (temp) {
        st.push(temp);
        if (!foundOne) {
          ancestors.push(temp);
        }
        temp = temp->left;
      } else {
        TreeNode *top = st.top();
        if (top->right && top->right != recent) {
          temp = top->right;
        } else {
          if (top == p || top == q) {
            if (!foundOne) {
              foundOne = true;
            } else {
              while (top != ancestors.top()) {
                st.pop();
                top = st.top();
              }
              *r = top;
              break;
            }
          }
          st.pop();
          if (top == ancestors.top()) {
            ancestors.pop();
          }
          recent = top;
          temp = NULL;
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
  // root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->left = new TreeNode(6);
  // root->right->left = new TreeNode(6);
  TreeNode *r;
  // sln.ancestor(root, root->left->left, root->left, &r);
  // cout << r->value << endl;
  sln.ancestor(root, root->left, root->left->right, &r);
  cout << r->value << endl;

  return 0;
}