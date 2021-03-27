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
  int *getPostOrderOfFullTree(int *preorder, int n) {
    int *postorder = new int[n];
    for (int i = 0; i < n; ++i) {
      postorder[i] = preorder[i];
    }
    toPostOrder(postorder, 0, n - 1);

    return postorder;
  }

 private:
  void toPostOrder(int *postorder, int start, int end) {
    if (start + 1 >= end) {
      return;
    }
    int temp = postorder[start];
    for (int i = start + 1; i <= end; ++i) {
      postorder[i - 1] = postorder[i];
    }
    postorder[end] = temp;
    toPostOrder(postorder, start, start + (end - start) / 2 - 1);
    toPostOrder(postorder, start + (end - start) / 2, end - 1);
  }
};

int main() {
  Solution sln;
  int preorder[7] = {1, 2, 4, 5, 3, 6, 7};
  int *postorder = sln.getPostOrderOfFullTree(preorder, 7);
  for (int i = 0; i < 7; ++i) {
    cout << postorder[i] << endl;
  }

  return 0;
}