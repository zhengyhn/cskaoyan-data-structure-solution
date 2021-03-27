#include <iostream>

using namespace std;

class Solution {
  public:
    char findNearestAncestor(char *tree, int i, int j) {
      while (i >= 0 && j >= 0) {
        int iParent = (i - 1) / 2;
        int jParent = (j - 1) / 2;
        if (iParent == jParent) {
          return tree[iParent];
        } else {
          i = iParent;
          j = jParent;
        }
      }
      return 0; 
    }
};

int main() {
  Solution sln;
  char tree[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
  cout << sln.findNearestAncestor(tree, 3, 5) << endl;
  cout << sln.findNearestAncestor(tree, 5, 6) << endl;

  return 0;
}