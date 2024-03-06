#include <cstdlib>
#include <iostream>
using namespace std;

class MyStack {

private:
  struct Stack {
    int size;
    int top;
    int *next;
  };

  struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));

  auto isEmpty() -> int {
    if (s->top != -1) {
      return 0;
    } else {
      return 1;
    }
  };
  auto isFull() -> int {
    if (s->top == s->size - 1) {
      return 1;
    } else {
      return 0;
    }
  };

public:
  MyStack(int size) {
    s->size = size;
    s->top = -1;
    s->next = (int *)malloc(s->size * sizeof(int));
  };

  auto push(int value) -> void {
    if (this->isFull()) {
      cout << "Stack is full" << endl;
    } else {
      s->top++;
      s->next[s->top] = value;
    }
  };

  auto pop() -> int {
    if (this->isEmpty()) {
      cout << "Overflow!!!" << endl;
      return -1;
    } else {
      int val = s->next[s->top];
      s->top = s->top - 1;
      return val;
    }
  };

  auto display() -> void {
    for (int i = 0; i <= s->top; i++) {
      cout << s->next[i] << endl;
    }
  };
};

int main() {
  MyStack stack(20);
  stack.push(10);
  stack.push(20);
  stack.push(50);
  int poped = stack.pop();
  stack.display();
  cout << "popped elemet is :> "<<poped << endl;

  return 0;
}