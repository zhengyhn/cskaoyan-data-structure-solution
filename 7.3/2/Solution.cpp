#include <iostream>

using namespace std;

class Solution {
 public:
  void biBubbleSort(int *arr, int n) {
    bool done = false;
    int start = 0;
    int end = n - 1;
    for (int i = 0; !done && i < n; ++i) {
      int ascendDone = true;
      int descendDone = true;
      if (i % 2 == 0) {
        for (int i = start; i < end; ++i) {
          if (arr[i] > arr[i + 1]) {
            swap(arr, i, i + 1);
            ascendDone = false;
          }
        }
        if (!ascendDone) {
          --end;
        }
      } else {
        for (int i = end; i > start; --i) {
          if (arr[i] < arr[i - 1]) {
            swap(arr, i, i - 1);
            descendDone = false;
          }
        }
        if (!descendDone) {
          ++start;
        }
      }
      done = ascendDone && descendDone;
    }
  }
  void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
};

int main() {
  Solution sln;
  int *arr = new int[8]{5, 2, 3, 1, 6, 7, 10, 8};
  sln.biBubbleSort(arr, 8);
  for (int i = 0; i < 8; ++i) {
    cout << arr[i] << endl;
  }

  return 0;
}