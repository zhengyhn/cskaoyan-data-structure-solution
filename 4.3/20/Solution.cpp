#include <iostream>
#include <stack>

using namespace std;

typedef struct node {
  char data[10];
  struct node *left, *right;
}BTree;

class Solution {
 public:
  void printMidExpr(BTree *root) {
    __printMidExpr(root, true);
    cout << endl;
  }

  void __printMidExpr(BTree *root, bool isRoot) {
    if (!root) {
      return;
    }
    bool printBracket = !isRoot && (root->left || root->right);
    if (printBracket) {
      cout << "(";
    }
    __printMidExpr(root->left, false);
    cout << *(root->data);
    __printMidExpr(root->right, false);
    if (printBracket) {
      cout << ")";
    }
  }

  BTree *buildTree(const char *tree, int start, int end) {
    if (start > end || tree[start] == '\0') {
      return NULL;
    }
    BTree *root = (BTree *)malloc(sizeof(BTree));
    root->data[0] = tree[start];
    root->left = buildTree(tree, 2 * start + 1, end);
    root->right = buildTree(tree, 2 * start + 2, end);

    return root;
  }

  void preorder(BTree *root) {
    if (!root) {
      return;
    }
    cout << root->data << endl;
    preorder(root->left);
    preorder(root->right);
  }
};

int main() {
  Solution sln;
  // const char *tree = "*+*abc-\0\0\0\0\0\0\0d";
  const char *tree = "+*-ab\0-\0\0\0\0\0\0cd";
  BTree *root = sln.buildTree(tree, 0, 14);
  // sln.preorder(root);
  sln.printMidExpr(root);

  return 0;
}