#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
  int value;
  TreeNode *firstChild;
  TreeNode *nextSibling;
  TreeNode(int val) : value(val) {}
};

class Solution {
 public:
  int getNumLeaves(TreeNode *root) {
    if (!root) {
      return 0;
    }
    int num = 0;
    if (!root->firstChild) {
      ++num;
    }
    num += getNumLeaves(root->firstChild) + getNumLeaves(root->nextSibling);
    return num;
  }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(1);
  root->firstChild = new TreeNode(2);
  root->firstChild->nextSibling = new TreeNode(3);
  root->firstChild->nextSibling->nextSibling = new TreeNode(4);
  root->firstChild->firstChild = new TreeNode(5);
  root->firstChild->firstChild->nextSibling = new TreeNode(6);
  root->firstChild->firstChild->nextSibling->firstChild = new TreeNode(7);
  cout << sln.getNumLeaves(root) << endl;

  return 0;
}