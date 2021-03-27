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
  int getMaxWidth(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    int maxWidth = 0;
    while (!q.empty()) {
      int len = q.size();
      maxWidth = max(maxWidth, len);
      for (int i = 0; i < len; ++i) {
        TreeNode *front = q.front();
        q.pop();
        if (front->left) {
          q.push(front->left);
        }
        if (front->right) {
          q.push(front->right);
        }
      }
    }  
    return maxWidth;
  }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->left = new TreeNode(6);
  root->right->left = new TreeNode(6);
  cout << sln.getMaxWidth(root) << endl;

  return 0;
}