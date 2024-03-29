#include <iostream>
#include "../list.h"

using namespace std;

class Solution {
 public:
  void removeValue(List &list, int s, int t) {
    if (list.len <= 0 || s >= t) {
      cout << "Input invalid";
      return;
    }
    int i = 0;
    for (; i < list.len; ++i) {
      if (list.data[i] >= s) {
        break;
      }
    }
    int j = i;
    for (; j < list.len; ++j) {
      if (list.data[j] >= t) {
        break;
      }
    }
    while (j < list.len) {
      list.data[i++] = list.data[j++];
    }
    list.len = i;
  }
};

int main() {
  Solution sln;
  int arr[4] = {1, 2, 2, 3};
  List list(arr, 4);
  sln.removeValue(list, 1, 3);
  for (int i = 0; i < list.len; ++i) {
    cout << list.data[i] << endl;
  }

  return 0;
}