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
  bool isCompleteTree(TreeNode *root) {
    if (root == NULL) {
      return true;
    }
    queue<TreeNode *> q;
    q.push(root); 
    bool end = false;
    while (!q.empty()) {
      TreeNode *top = q.front();
      q.pop();
      if (top->left == NULL) {
        if (top->right != NULL) {
          return false;
        } else {
          end = true;
          continue;
        }
      } else {
        if (end) {
          return false;
        }
        if (top->right != NULL) {
          q.push(top->left);
          q.push(top->right);
        } else {
          end = true;
          continue;
        }
      }
    }
    return true;
  }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  cout << sln.isCompleteTree(root) << endl;
  root->right->right = new TreeNode(6);
  cout << sln.isCompleteTree(root) << endl;

  return 0;
}