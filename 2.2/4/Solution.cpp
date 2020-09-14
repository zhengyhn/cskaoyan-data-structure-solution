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
    for (int i = 0; i < list.len; ++i) {
      if (list.data[i] == s) {
        int start = i;
        while (list.data[i] <= t) {
          ++i;
        } 
        for (int j = start, k = i; k < list.len; ++j, ++k) {
          list.data[j] = list.data[k];
        }
        list.len -= i - start;
      }
    }
  }
};

int main() {
  Solution sln;
  int arr[4] = {1, 2, 2, 3};
  List list(arr, 4);
  sln.removeValue(list, 1, 2);
  for (int i = 0; i < list.len; ++i) {
    cout << list.data[i] << endl;
  }

  return 0;
}