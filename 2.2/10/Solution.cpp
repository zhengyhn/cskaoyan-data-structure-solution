#include <iostream>
#include "../list.h"

using namespace std;

class Solution {
 public:
  void reverseAtPos(ElementType arr[], int len, int p) {
    reverse(arr, 0, p - 1);
    reverse(arr, p, len - 1);
    reverse(arr, 0, len - 1); 
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
  int arr[] = {1, 2, 2, 3};
  sln.reverseAtPos(arr, 4, 2);
  for (int i = 0; i < 4; ++i) {
    cout << arr[i] << endl;
  }
  return 0;
}