#include <iostream>
#include "../list.h"

using namespace std;

class Solution {
 public:
  int findMedium(List &left, List &right) {
    int i = 0;
    int j = 0;
    int pos = (left.len + right.len - 2) / 2;
    int k = -1;
    while (i < left.len && j < right.len) {
      int value = 0;
      if (left.data[i] < right.data[j]) {
        value = left.data[i];
        ++i;
      } else {
        value = right.data[j];
        ++j;
      }
      ++k;
      if (k == pos) {
        return value;
      }
    }
    cout << i << " " << pos << " " << k << endl;
    if (i < left.len) {
      return left.data[i + pos - k - 1];
    }
    return right.data[j + pos - k - 1];
  }
};

int main() {
  Solution sln;
  int arr1[] = {11, 13, 15, 17, 19};
  List left(arr1, 5);
  int arr2[] = {2, 4, 6, 8, 12};
  List right(arr2, 5);
  cout << sln.findMedium(left, right) << endl;

  return 0;
}