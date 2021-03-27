#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
  int weight;
  TreeNode *left;
  TreeNode *right;

 public:
  TreeNode(int val) : weight(val) {}
};

class Solution {
 public:
  int getWpl(TreeNode *root) {
    stack<TreeNode *> st;
    int wpl = 0;
    if (!root) {
      return wpl;
    }
    st.push(root);
    while (!st.empty()) {
      TreeNode *top = st.top();
      st.pop();
      if (!top->left && !top->right) {
        wpl += top->weight;
      }
      if (top->right) {
        st.push(top->right);
      }
      if (top->left) {
        st.push(top->left);
      }
    }
    return wpl;
  }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  cout << sln.getWpl(root) << endl;

  return 0;
}