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
  TreeNode *buildTree(int *preorder, int *inorder, int len) {
    return buildSubTree(preorder, 0, len - 1, inorder, 0, len - 1);
  }

  TreeNode *buildSubTree(int *preorder, int pStart, int pEnd, int *inorder, int iStart, int iEnd) {
    if (pStart > pEnd || iStart > iEnd) {
      return NULL;
    }
    TreeNode *node = new TreeNode(preorder[pStart]);
    int i = iStart;
    for (; i <= iEnd; ++i) {
      if (inorder[i] == preorder[pStart]) {
        break;
      }
    }
    if (i > iEnd) {
      return NULL;
    }
    node->left = buildSubTree(preorder, pStart + 1, pStart + i - iStart, inorder, 0, i - 1);
    node->right = buildSubTree(preorder, pStart + i - iStart + 1, pEnd, inorder, i + 1, iEnd);

    return node;
  }

  void preorder(TreeNode *root) {
    if (root == NULL) {
      return;
    }
    cout << root->value << endl;
    preorder(root->left);
    preorder(root->right);
  }

  void inorder(TreeNode *root) {
    stack<TreeNode *> st;
    TreeNode *p = root;
    while (p != NULL || !st.empty()) {
      if (p != NULL) {
        st.push(p);
        p = p->left;
      } else {
        TreeNode *top = st.top();
        cout << top->value << endl;
        st.pop();
        if (top->right != NULL) {
          p = top->right;
        }
      }
    }
  }
};

int main() {
  Solution sln;
  int preorder[] = {1, 2, 4, 5, 3};
  int inorder[] = {4, 2, 5, 1, 3};

  TreeNode *root = sln.buildTree(preorder, inorder, 5);
  sln.preorder(root);
  cout << "-----------" << endl;
  sln.inorder(root);

  return 0;
}