#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isMinHeap(vector<int> v) {
    for (int i = 0; i <= v.size() / 2; ++i) {
      int left = 2 * i + 1;
      int right = left + 1;
      if (left < v.size() && v[i] > v[left]) {
        return false;
      }
      if (right < v.size() && v[i] > v[left]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution sln;
  vector<int> v{5, 2, 3, 1, 6, 7, 10, 8};
  cout << sln.isMinHeap(v) << endl;
  vector<int> v2{1, 2, 3, 4, 5};
  cout << sln.isMinHeap(v2) << endl;

  return 0;
}