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
  bool isBalancedTree(TreeNode *root) {
    int depth = 0;
    return __isBalancedTree(root, &depth);
  }

  bool __isBalancedTree(TreeNode *root, int *depth) {
    if (!root) {
      *depth = 0;
      return true;
    }
    int depthLeft = 0;
    int depthRight = 0;
    bool isLeftBalanced = __isBalancedTree(root->left, &depthLeft);
    bool isRightBalanced = __isBalancedTree(root->right, &depthRight);
    *depth = 1 + max(depthRight, depthLeft);
    if (abs(depthRight - depthLeft) > 1) {
      return false;
    } else {
      return isLeftBalanced && isRightBalanced;
    }
  }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->left->right = new TreeNode(2);
  root->right = new TreeNode(4);
  cout << sln.isBalancedTree(root) << endl;
  root->right->left = new TreeNode(5);
  cout << sln.isBalancedTree(root) << endl;
  root->left->right->left = new TreeNode(6);
  cout << sln.isBalancedTree(root) << endl;

  return 0;
}