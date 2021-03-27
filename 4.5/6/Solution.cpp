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
  bool isBst(TreeNode *root) {
    if (!root) {
      return true;
    }
    if (root->left && root->left->value > root->value) {
      return false;
    }
    if (root->right && root->right->value < root->value) {
      return false;
    }
    return isBst(root->left) && isBst(root->right);
  }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->left->right = new TreeNode(2);
  root->right = new TreeNode(4);
  cout << sln.isBst(root) << endl;
  root->right->left = new TreeNode(5);
  cout << sln.isBst(root) << endl;

  return 0;
}