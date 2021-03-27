#include <iostream>
#include <stack>

using namespace std;

class Solution {
 public:
  void qSort(int *arr, int n) {
    stack<int> st;
    st.push(n - 1);
    st.push(0);
    while (!st.empty()) {
      int left = st.top();
      st.pop();
      int right = st.top();
      st.pop();
      int r = left + (rand() % (right - left + 1));
      swap(arr, left, r);
      int pivot = arr[left];
      int low = left;
      int high = right;
      while (low < high) {
        while (low < high && arr[high] >= pivot) {
          --high;
        }
        arr[low] = arr[high];
        while (low < high && arr[low] <= pivot) {
          ++low;
        }
        arr[high] = arr[low];
      }
      arr[low] = pivot;
      if (low > left && low < right) {
        st.push(right);
        st.push(low + 1);
        st.push(low - 1);
        st.push(left);
      }
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
  int arr[8] = {5, 2, 3, 1, 6, 7, 10, 8};
  sln.qSort(arr, 8);
  for (int i = 0; i < 8; ++i) {
    cout << arr[i] << endl;
  }

  return 0;
}