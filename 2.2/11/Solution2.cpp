#include <iostream>
#include "../list.h"

using namespace std;

class Solution {
 public:
  int findMedium(List &left, List &right) {
    int leftBegin = 0;
    int leftEnd = left.len - 1;
    int rightBegin = 0;
    int rightEnd = right.len - 1;
    int leftMid = 0;
    int rightMid = 0;
    while (leftBegin < leftEnd && rightBegin < rightEnd) {
      leftMid = leftBegin + (leftEnd - leftBegin) / 2;
      rightMid = rightBegin + (rightEnd - rightBegin) / 2;
      if (left.data[leftMid] == right.data[rightMid]) {
        return left.data[leftMid];
      } else if (left.data[leftMid] < right.data[rightMid]) {
        if ((leftBegin + leftEnd) % 2 == 0) {
          leftBegin = leftMid;
        } else {
          leftBegin = leftMid + 1;
        }
        rightEnd = rightMid;
      } else {
        if ((leftBegin + leftEnd) % 2 == 0) {
          rightBegin = rightMid;
        } else {
          rightBegin = rightMid + 1;
        }
        leftEnd = leftMid;
      }
    } 
    return min(left.data[leftBegin], right.data[rightBegin]);
  }
};

int main() {
  Solution sln;
  int arr1[] = {11, 13, 15, 17, 19};
  List left(arr1, 5);
  int arr2[] = {2, 4, 6, 8, 20};
  List right(arr2, 5);
  cout << sln.findMedium(left, right) << endl;

  return 0;
}