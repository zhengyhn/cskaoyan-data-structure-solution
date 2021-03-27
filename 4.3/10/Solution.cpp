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
  int getPreorderValue(TreeNode *root, int k) {
    stack<TreeNode *> st;
    st.push(root);
    int i = 0;
    while (!st.empty()) {
      TreeNode *top = st.top();
      st.pop();
      ++i;
      if (i == k) {
        return top->value;
      }
      if (top->right != NULL) {
        st.push(top->right);
      }
      if (top->left != NULL) {
        st.push(top->left);
      }
    }
    return -1;
  }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  for (int i = 1; i <= 5; ++i) {
    cout << sln.getPreorderValue(root, i) << endl;
  }

  return 0;
}