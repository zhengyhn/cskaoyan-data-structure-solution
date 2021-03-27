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
  bool removeByValue(TreeNode *root, int x) {
    if (root == NULL) {
      return false;
    }
    if (root->value == x) {
      deleteCascade(root);
      return true;
    } else {
      bool done = removeByValue(root->left, x);
      if (done) {
        root->left = NULL;
      }
      done = removeByValue(root->right, x);
      if (done) {
        root->right = NULL;
      }
      return false;
    }
  }

  void preorder(TreeNode *root) {
    if (root == NULL) {
      return;
    }
    cout << root->value << endl;
    preorder(root->left);
    preorder(root->right);
  }

 private:
  void deleteCascade(TreeNode *root) {
    if (root == NULL) {
      return;
    }
    deleteCascade(root->left);
    deleteCascade(root->right);
    delete root;
  }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  sln.removeByValue(root, 2);
  sln.preorder(root);

  sln.removeByValue(root, 3);
  cout << "----------" << endl;
  sln.preorder(root);

  return 0;
}