#include <iostream>

#include "../list.h"

using namespace std;

class Solution {
 public:
  ElementType removeSmallest(List &list) {
    if (list.len <= 0) {
      cerr << "Array size invalid" << endl;
      exit(1);
    }
    int min = 0;
    for (int i = 1; i < list.len; ++i) {
      if (list.data[i] < list.data[min]) {
        min = i;
      }
    }
    ElementType temp = list.data[min];
    if (min != list.len - 1) {
      list.data[min] = list.data[list.len - 1];
    }
    list.len -= 1;

    return temp;
  }
};

int main() {
  Solution sln;
  int arr[3] = {1, 2, 3};
  List list(arr, 3);
  cout << "Smallest: " << sln.removeSmallest(list) << endl;
  cout << "Rest elements: " << endl;
  for (int i = 0; i < list.len; ++i) {
    cout << list.data[i] << endl;
  }

  return 0;
}