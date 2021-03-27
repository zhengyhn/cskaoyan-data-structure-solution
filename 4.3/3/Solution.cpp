#include <iostream>
#include <stack>
#include <vector>

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
 void midOrder2(TreeNode *root) {
   stack<TreeNode *> st;
   TreeNode *p = root;
   while (p != NULL || !st.empty()) {
     if (p != NULL) {
       st.push(p);
       p = p->left;
     } else {
       p = st.top();
       cout << p->value << endl;
       st.pop();
       p = p->right;
     }
   }
 }
  void midOrder(TreeNode *root) {
    stack<TreeNode *> st;
    TreeNode *p = root;
    while (!st.empty() || p != NULL) {
      while (p != NULL) {
        st.push(p);
        p = p->left;
      }
      if (st.empty()) {
        break;
      }
      TreeNode *top = st.top();
      cout << top->value << endl;
      st.pop();
      if (top->right != NULL) {
        p = top->right;
      }
    }
  }

  void postOrder(TreeNode *root) {
    vector<int> list;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty()) {
      TreeNode *p = st.top();
      st.pop();
      list.push_back(p->value);
      if (p->left != NULL) {
        st.push(p->left);
      }
      if (p->right != NULL) {
        st.push(p->right);
      }
    }
    for (int i = list.size() - 1; i >= 0; --i) {
      cout << list[i] << endl;
    }
  }

  void postOrder2(TreeNode *root) {
    stack<TreeNode *> st;
    TreeNode *p = root;
    TreeNode *recent = NULL;
    while (p != NULL || !st.empty()) {
      if (p != NULL) {
        st.push(p);
        p = p->left;
      } else {
        TreeNode *top = st.top();
        if (top->right != NULL && top->right != recent) {
          p = top->right;
        } else {
          cout << top->value << endl;
          st.pop();
          recent = top;
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
  // sln.midOrder(root);
  // sln.midOrder2(root);
  // sln.postOrder(root);
  sln.postOrder2(root);

  return 0;
}