#include <iostream>
#include "../list.h"

using namespace std;

class Solution {
 public:
  void reverseTwoList(ElementType arr[], int m, int n) {
    int size = m + n;
    reverse(arr, 0, m - 1);
    reverse(arr, m, size - 1);
    reverse(arr, 0, size - 1); 
  }

  void reverse(ElementType *arr, int begin, int end) {
    while (begin < end) {
      ElementType temp = arr[begin];
      arr[begin] = arr[end];
      arr[end] = temp;
      ++begin;
      --end;
    }
  }
};

int main() {
  Solution sln;
  int arr[] = {1, 2, 2, 3, 1, 2, 2};
  sln.reverseTwoList(arr, 4, 3);
  for (int i = 0; i < 7; ++i) {
    cout << arr[i] << endl;
  }
  return 0;
}