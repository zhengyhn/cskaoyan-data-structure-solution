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
    int j = 0;
    int len = list.len;
    while (i <= j && j < len) {
      while (j < len && list.data[j] >= s && list.data[j] <= t) {
        ++j;
        --list.len;
      }
      if (j < len) {
        list.data[i++] = list.data[j++];
      }
    }
  }
};

int main() {
  Solution sln;
  int arr[4] = {3, 2, 2, 1};
  List list(arr, 4);
  sln.removeValue(list, 1, 2);
  for (int i = 0; i < list.len; ++i) {
    cout << list.data[i] << endl;
  }

  return 0;
}