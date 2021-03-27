#include <iostream>
#include <stack>

using namespace std;

class Solution {
  public:
    bool isMatch(string exp) {
      stack<char> st;
      int map[129];
      map[')'] = '(';
      map[']'] = '[';
      map['}'] = '{';
      for (int i = 0; i < exp.size(); ++i) {
        switch (exp[i]) {
          case '(':
          case '[':
          case '{':
            st.push(exp[i]);
            break;
          case ')':
          case ']':
          case '}':
            if (!st.empty() && st.top() == map[exp[i]]) {
              st.pop();
            } else {
              return false;
            }
            break;
          default:
            break;
        }
      }
      return st.empty();
    }
};

int main() {
  Solution sln;
  cout << sln.isMatch("(1 + 2) * {123 + [123 - 2]}") << endl;
  cout << sln.isMatch("(1 + 2) (*} {123 + [123 - 2]}") << endl;

  return 0;
}