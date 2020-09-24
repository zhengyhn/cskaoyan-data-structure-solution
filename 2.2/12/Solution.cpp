#include <iostream>
#include "../list.h"

using namespace std;

class Solution {
 public:
  int findMajority(List &list) {
    if (list.len <= 0) {
      return -1;
    }
    int count = 1;
    int prev = list.data[0];
    for (int i = 1; i < list.len; ++i) {
      if (count == 0) {
        ++count;
      } else if (list.data[i] == prev) {
        ++count;
      } else {
        --count;
      }
      prev = list.data[i];
    }
    if (count > 0) {
      int temp = 0;
      for (int i = 0; i < list.len; ++i) {
        if (list.data[i] == prev) {
          ++temp;
        }
      }
      if (temp >= list.len / 2) {
        return prev;
      }
    }
    return -1;
  }
};

int main() {
  Solution sln;
  int arr1[] = {0, 5, 5, 3, 5, 7, 5, 5};
  List left(arr1, 8);
  cout << sln.findMajority(left) << endl;
  int arr2[] = {0, 5, 5, 3, 5, 1, 5, 7};
  List right(arr2, 8);
  cout << sln.findMajority(right) << endl;
  int arr3[] = {0, 5, 0, 5, 0, 5, 7};
  List list3(arr3, 7);
  cout << sln.findMajority(list3) << endl;

  return 0;
}