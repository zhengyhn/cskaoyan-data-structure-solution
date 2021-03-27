#include <iostream>
#include <stack>

using namespace std;

class Solution {
  public:
    int calculate(int n, int x) {
      stack<int> st;
      if (n == 0) {
        return 1;
      }
      st.push(1);
      if (n == 1) {
        return 2 * x;
      }
      st.push(2 * x);
      for (int i = 2; i <= n; ++i) {
        int right = st.top();
        st.pop();
        int left = st.top();
        st.pop();
        int value = 2 * x * right - 2 * (i - 1) * left;
        st.push(right);
        st.push(value);
      }
      return st.top();
    }
};

int main() {
  Solution sln;
  cout << sln.calculate(0, 2) << endl;
  cout << sln.calculate(1, 2) << endl;
  cout << sln.calculate(2, 2) << endl;
  cout << sln.calculate(3, 2) << endl;

  return 0;
}