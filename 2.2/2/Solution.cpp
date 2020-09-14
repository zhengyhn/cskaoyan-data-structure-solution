#include <iostream>
#include "../list.h"

using namespace std;

class Solution {
 public:
  void reverse(List &list) {
    if (list.len <= 0) {
      return;
    }
    int left = 0;
    int right = list.len - 1;
    while (left < right) {
      int temp = list.data[left];
      list.data[left] = list.data[right];
      list.data[right] = temp;
      ++left;
      --right;
    }
  }
};

int main() {
  Solution sln;
  int arr[3] = {1, 2, 3};
  List list(arr, 3);
  sln.reverse(list);
  for (int i = 0; i < list.len; ++i) {
    cout << list.data[i] << endl;
  }

  return 0;
}