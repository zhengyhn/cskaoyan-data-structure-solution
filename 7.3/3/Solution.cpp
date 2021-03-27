#include <iostream>

using namespace std;

class Solution {
 public:
  void partition(int *arr, int n) {
    int pivot = arr[0];
    int low = 0;
    int high = n - 1;
    while (low < high) {
      while (low < high && arr[high] % 2 == 0) {
        --high;
      }
      arr[low] = arr[high];
      while (low < high && arr[low] % 2 == 1) {
        ++low;
      }
      arr[high] = arr[low];
    }
    arr[low] = pivot;
  }
};

int main() {
  Solution sln;
  int *arr = new int[8]{5, 2, 3, 1, 6, 7, 10, 8};
  sln.partition(arr, 8);
  for (int i = 0; i < 8; ++i) {
    cout << arr[i] << endl;
  }

  return 0;
}