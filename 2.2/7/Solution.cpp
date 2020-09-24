#include <iostream>
#include "../list.h"

using namespace std;

class Solution {
 public:
  List mergeList(List &left, List &right) {
    int size = left.len + right.len;
    if (size <= 0) {
      cerr << "Invalid input";
      exit(1);
    }
    ElementType data[size];
    List ret(data, size);
    int i = 0; 
    int j = 0;
    int k = 0;
    while (i < left.len && j < right.len) {
      if (left.data[i] < right.data[j]) {
        ret.data[k++] = left.data[i++];
      } else {
        ret.data[k++] = right.data[j++];
      }
    }
    while (i < left.len) {
        ret.data[k++] = left.data[i++];
    }
    while (j < right.len) {
        ret.data[k++] = right.data[j++];
    }
    return ret;
  }
};

int main() {
  Solution sln;
  int arr[4] = {1, 2, 2, 3};
  List list(arr, 4);
  List ret = sln.mergeList(list, list);
  for (int i = 0; i < ret.len; ++i) {
    cout << ret.data[i] << endl;
  }
  return 0;
}