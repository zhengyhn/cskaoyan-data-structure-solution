#include <iostream>
#include <stack>

using namespace std;

class Solution {
  public:
    void adjust(string exp) {
      stack<string> st;
      int j = 0;
      for (int i = 0; i < exp.size(); ++i) {
        if (exp[i] == 'H') {
          cout << "Push H" << i << endl;
          st.push("H" + to_string(i));
        } else {
          cout << "Pass S" << i << endl;
        }
      }
      while (!st.empty()) {
        cout << "Pop and Pass " << st.top() << endl;
        st.pop();
      }
    }
};

int main() {
  Solution sln;
  sln.adjust("SHHHHHSHSSSSH");

  return 0;
}