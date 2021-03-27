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
  int getDepth(TreeNode *root, TreeNode *node) {
    int depth = 0;
    TreeNode *p = root;
    while (p && p != node) {
      ++depth;
      if (node->value <= p->value) {
        p = p->left;
      } else {
        p = p->right;
      }
    }
    if (p == node) {
      return depth + 1;
    } else {
      return 0;
    }
  }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->left->right = new TreeNode(2);
  root->right = new TreeNode(4);
  cout << sln.getDepth(root, root->left->right) << endl;
  cout << sln.getDepth(root, root->right) << endl;

  return 0;
}