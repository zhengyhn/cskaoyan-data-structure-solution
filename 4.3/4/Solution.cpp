#include <iostream>
#include <stack>
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
 void bottomUpTravel(TreeNode *root) {
   stack<TreeNode *> st;
   queue<TreeNode *> q;
   q.push(root);
   while (!q.empty()) {
     TreeNode *front = q.front();
     q.pop();
     st.push(front);
     if (front->left != NULL) {
       q.push(front->left);
     }
     if (front->right != NULL) {
       q.push(front->right);
     }
   }
   while (!st.empty()) {
     cout << st.top()->value << endl;
     st.pop();
   }
 }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  sln.bottomUpTravel(root);

  return 0;
}