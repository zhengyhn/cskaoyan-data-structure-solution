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
  int countDoubleNode(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }
    queue<TreeNode *> q;
    q.push(root); 
    int count = 0;
    while (!q.empty()) {
      TreeNode *top = q.front();
      q.pop();
      if (top->left != NULL && top->right != NULL) {
        ++count;
      }
      if (top->left != NULL) {
        q.push(top->left);
      }
      if (top->right != NULL) {
        q.push(top->right);
      }
    }
    return count;
  }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  cout << sln.countDoubleNode(root) << endl;
  root->right->right = new TreeNode(6);
  cout << sln.countDoubleNode(root) << endl;

  return 0;
}