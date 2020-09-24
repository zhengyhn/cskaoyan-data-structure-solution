#include <iostream>
#include "../list.h"

using namespace std;

class Solution {
 public:
  void removeValue(List &list) {
    if (list.len <= 0) {
      cout << "Input invalid";
      return;
    }
    int i = 0;
    int j = i + 1;
    for (; j < list.len; ++j) {
      if (list.data[j] != list.data[i]) {
        list.data[++i] = list.data[j];
      }
    } 
    list.len = i + 1;
  }
};

int main() {
  Solution sln;
  int arr[4] = {1, 2, 2, 3};
  List list(arr, 4);
  sln.removeValue(list);
  for (int i = 0; i < list.len; ++i) {
    cout << list.data[i] << endl;
  }

  return 0;
}