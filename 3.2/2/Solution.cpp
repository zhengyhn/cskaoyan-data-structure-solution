#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Solution {
 public:
  void revert(queue<int> &q) {
    stack<int> s;
    while (!q.empty()) {
      s.push(q.front());
      q.pop();
    }
    while (!s.empty()) {
      q.push(s.top());
      s.pop();
    }
  }
};

int main() {
  Solution sln;
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  sln.revert(q);
  while (!q.empty()) {
    cout << q.front() << endl;
    q.pop();
  }

  return 0;
}