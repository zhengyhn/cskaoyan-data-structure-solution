#include <iostream>

using namespace std;

class Solution {
 public:
  bool isValid(const char *list, int len) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
      if (count == 0 && list[i] == 'O') {
        return false;
      }
      if (list[i] == 'I') {
        ++count;
      } else {
        --count;
      }
    }
    return count == 0;
  }
};

int main() {
  Solution sln;
  string list[] = {"IOIIOIOO", "IOOIOIIO", "IIIOIOIO", "IIIOOIOO"};
  int len = sizeof(list) / sizeof(string);
  for (int i = 0; i < len; ++i) {
    cout << sln.isValid(list[i].data(), list[i].size()) << endl;
  }
  return 0;
}