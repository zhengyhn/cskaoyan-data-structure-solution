#include <iostream>
#include <queue>
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
  int getHeight(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    int height = 0;
    while (!q.empty()) {
      ++height;
      int len = q.size();
      for (int i = 0; i < len; ++i) {
        TreeNode *front = q.front();
        q.pop();
        if (front->left != NULL) {
          q.push(front->left);
        }
        if (front->right != NULL) {
          q.push(front->right);
        }
      }
    }
    return height;
  }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  cout << sln.getHeight(root) << endl;

  return 0;
}