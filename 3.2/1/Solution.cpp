#include <iostream>

using namespace std;

const int MAX_SIZE = 5;

class CycleQueue {
  private:
    int data[MAX_SIZE];
    int front = -1;
    int rear = -1;
    int tag = 0;
  public:
    bool isEmpty() {
      return tag == 0 && front == rear;
    } 
    bool isFull() {
      return tag == 1 && front == rear;
    } 
    void push(int value) {
      rear = (++rear) % MAX_SIZE;
      data[rear] = value; 
      if (tag == 0 && front == rear) {
        tag = 1;
      }
    }
    int poll() {
      front = (++front) % MAX_SIZE;
      int value = data[front]; 
      if (tag == 1 && front == rear) {
        tag = 0;
      }
      return value;
    }
};

int main() {
  CycleQueue queue;

  cout << queue.isEmpty() << endl;
  queue.push(1);
  cout << queue.isEmpty() << endl;
  cout << queue.poll() << endl;
  cout << queue.isEmpty() << endl;
  queue.push(2);
  queue.push(3);
  queue.push(4);
  queue.push(5);
  queue.push(6);
  cout << queue.isFull() << endl;

  return 0;
}