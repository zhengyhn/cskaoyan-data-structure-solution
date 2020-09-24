#include <iostream>

using namespace std;

const int MAX_SIZE = 5;

class DoubleStack {
  private:
    int data[MAX_SIZE];
    int leftTop = -1;
    int rightTop = MAX_SIZE;
  public:
    void leftPush(int item) {
      data[++leftTop] = item;
    }
    int leftPop() {
      return data[leftTop--];
    }

    bool isEmpty() {
      return leftTop == -1 && rightTop == MAX_SIZE;
    }

    bool isFull() {
      return rightTop - leftTop == 1; 
    }

    void rightPush(int item) { 
      data[--rightTop] = item; 
    }

    int rightPop() {
      return data[rightTop++];
    }
    int size() { 
      return (leftTop + 1) + (MAX_SIZE - rightTop); 
    }
};

int main() {
  DoubleStack stack;

  cout << stack.isEmpty() << endl;
  stack.leftPush(2);
  cout << stack.isEmpty() << endl;
  cout << stack.size() << endl;
  cout << stack.leftPop() << endl;
  cout << stack.isEmpty() << endl;
  cout << stack.size() << endl;
  stack.leftPush(2);
  stack.leftPush(3);
  stack.rightPush(3);
  stack.rightPush(4);
  stack.rightPush(5);
  cout << stack.size() << endl;
  cout << stack.isFull() << endl;
  cout << stack.rightPop() << endl;
  cout << stack.size() << endl;
  cout << stack.isFull() << endl;

  return 0;
}