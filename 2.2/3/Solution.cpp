#include <iostream>
#include "../list.h"

using namespace std;

class Solution {
 public:
  void removeValue(List &list, ElementType x) {
    if (list.len <= 0) {
      cerr << "Invalid input";
      exit(1);
    }
    int i = 0;
    int j = 0;
    int k = 0;
    while (j < list.len) {
      if (list.data[j] != x) {
        list.data[i++] = list.data[j];
        ++k;
      }
      ++j;
    }
    list.len = k;
  }
};

int main() {
  Solution sln;
  int arr[4] = {1, 2, 2, 3};
  List list(arr, 4);
  sln.removeValue(list, 2);
  for (int i = 0; i < list.len; ++i) {
    cout << list.data[i] << endl;
  }

  return 0;
}