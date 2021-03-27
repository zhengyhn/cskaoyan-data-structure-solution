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
  void getMinMax(TreeNode *root, int *mini, int *maxi) {
    TreeNode *p;
    *mini = root->value;
    p = root->left;
    while (p) {
      *mini = min(*mini, p->value);
      p = p->left;
    }
    *maxi = root->value;
    p = root->right;
    while (p) {
      *maxi = max(*maxi, p->value);
      p = p->right;
    }
  }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->left->right = new TreeNode(2);
  root->right = new TreeNode(4);
  root->right->right = new TreeNode(5);
  int min, max;
  sln.getMinMax(root, &min, &max);
  cout << min << " " << max << endl;

  return 0;
}