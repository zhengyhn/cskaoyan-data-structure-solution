#include <iostream>
#include <queue>

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
  TreeNode *swapLeftAndRight(TreeNode *root) {
    if (root == NULL) {
      return root;
    }
    TreeNode *left = swapLeftAndRight(root->right);
    TreeNode *right = swapLeftAndRight(root->left);
    root->left = left;
    root->right = right;
    return root;
  }

  void preorder(TreeNode *root) {
    if (root == NULL) {
      return;
    }
    cout << root->value << endl;
    preorder(root->left);
    preorder(root->right);
  }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  sln.swapLeftAndRight(root);
  sln.preorder(root);
  root->left->right = new TreeNode(6);
  sln.swapLeftAndRight(root);
  cout << "-----------" << endl;
  sln.preorder(root);

  return 0;
}