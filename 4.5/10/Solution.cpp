#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
  int value;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : value(val) {}
};

class Solution {
 public:
  void printGreaterThanK(TreeNode *root, int k) {
    stack<TreeNode *> st;
    stack<int> values;
    TreeNode *p = root;
    while (p || !st.empty()) {
      if (p) {
        st.push(p);
        p = p->left;
      } else {
        TreeNode *top = st.top();
        st.pop();
        if (top->value >= k) {
          values.push(top->value);
        }
        if (top->right) {
          p = top->right;
        }
      }
    }
    while (!values.empty()) {
      cout << values.top() << endl;
      values.pop();
    }
  }
  void printGreaterThanK2(TreeNode *root, int k) {
    if (!root) {
      return;
    }
    if (root->right) {
      printGreaterThanK2(root->right, k);
    }
    if (root->value >= k) {
      cout << root->value << endl;
    }
    if (root->left) {
      printGreaterThanK2(root->left, k);
    }
  }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->left->right = new TreeNode(2);
  root->right = new TreeNode(4);
  root->right->right = new TreeNode(5);
  sln.printGreaterThanK(root, 2);
  cout << "------------" << endl;
  sln.printGreaterThanK(root, 3);
  cout << "------------" << endl;
  sln.printGreaterThanK2(root, 2);
  cout << "------------" << endl;
  sln.printGreaterThanK2(root, 3);

  return 0;
}