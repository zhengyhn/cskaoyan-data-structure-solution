#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
  int value;
  TreeNode *left;
  TreeNode *right;
  int count;
  TreeNode(int val, int c) : value(val), count(c) {}
};

class Solution {
 public:
  TreeNode *findKsmallest(TreeNode *root, int k) {
    if (!root) {
      return root;
    }
    if (root->left) {
      if ((root->left->count + 1) >= k) {
        return findKsmallest(root->left, k);
      } else {
        k -= root->left->count + 1;
      }
    }
    if (k == 1) {
      return root;
    } else {
      return findKsmallest(root->right, k - 1);
    }
  }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(3, 4);
  root->left = new TreeNode(1, 1);
  root->left->right = new TreeNode(2, 0);
  root->right = new TreeNode(4, 1);
  root->right->right = new TreeNode(5, 0);
  for (int i = 1; i <= 5; ++i) {
    cout << sln.findKsmallest(root, i)->value << endl;
  }

  return 0;
}