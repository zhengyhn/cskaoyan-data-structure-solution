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
  bool isSimilar(TreeNode *leftTree, TreeNode *rightTree) {
    if (!leftTree && !rightTree) {
      return true;
    }
    if ((!leftTree && rightTree) || (leftTree && !rightTree)) {
      return false;
    }
    return isSimilar(leftTree->left, rightTree->left) && isSimilar(leftTree->right, rightTree->right);
  }
};

int main() {
  Solution sln;
  cout << sln.isSimilar(NULL, NULL) << endl;
  TreeNode *root = new TreeNode(1);
  TreeNode *root2 = new TreeNode(2);
  cout << sln.isSimilar(root, NULL) << endl;
  cout << sln.isSimilar(NULL, root) << endl;
  cout << sln.isSimilar(root, root2) << endl;

  root->left = new TreeNode(2);
  root2->right = new TreeNode(3);
  cout << sln.isSimilar(root, root2) << endl;

  root->right = new TreeNode(6);
  root2->left = new TreeNode(7);
  cout << sln.isSimilar(root, root2) << endl;

  return 0;
}