#include <iostream>
#include "../list.h"

using namespace std;

class Solution {
 public:
  void binSearch(List &list, int x) {
    int low = 0;
    int high = list.len - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (x == list.data[mid]) {
        if (mid + 1 < list.len) {
          swap(list.data[mid], list.data[mid + 1]);
        }
        return;
      } else if (list.data[mid] < x) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    ElementType *data = new ElementType[list.len + 1];
    for (int i = 0; i < low; ++i) {
      data[i] = list.data[i];
    }
    for (int i = list.len; i > low; --i) {
      data[i] = list.data[i - 1];
    }
    data[low] = x;
    delete list.data;
    list.data = data;
    list.len += 1;
  }
};

int main() {
  Solution sln;
  int arr[] = {1, 2, 3, 5};
  List list(arr, 4);
  // sln.binSearch(list, 3);
  // sln.binSearch(list, 4);
  // sln.binSearch(list, 2);
  // sln.binSearch(list, 1);
  // sln.binSearch(list, 6);
  // sln.binSearch(list, 0);
  sln.binSearch(list, 4);
  for (int i = 0; i < list.len; ++i) {
    cout << list.data[i] << endl;
  }
  return 0;
}