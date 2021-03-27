#include <iostream>
#include <queue>
#include <stack>

using namespace std;

const int MAX_SIZE = 5;

class Stack {
 private:
  int data[MAX_SIZE];
  int top = -1;

 public:
  bool isEmpty() {
    return top == -1;
  }
  bool isFull() {
    return top == MAX_SIZE - 1;
  }
  void push(int value) {
    data[++top] = value;
  }
  int pop() {
    return data[top--];
  }
};

class Queue {
 private:
  Stack s1;
  Stack s2;

 public:
  void enQueue(int x) {
    if (s1.isFull() && s2.isEmpty()) {
      while (!s1.isEmpty()) {
        s2.push(s1.pop());
      }
    }
    s1.push(x);
  }
  int deQueue() {
    if (s2.isEmpty()) {
      while (!s1.isEmpty()) {
        s2.push(s1.pop());
      }
    }
    return s2.pop();
  }
  bool isEmpty() {
    return s1.isEmpty() && s2.isEmpty();
  }
};

int main() {
  Queue q;
  q.enQueue(1);
  q.enQueue(2);
  cout << q.deQueue() << endl;
  cout << q.deQueue() << endl;
  q.enQueue(3);
  q.enQueue(4);
  q.enQueue(5);
  q.enQueue(6);
  q.enQueue(7);
  q.enQueue(8);

  while (!q.isEmpty()) {
    cout << q.deQueue() << endl;
  }

  return 0;
}