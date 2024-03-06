#include <cstdlib>
#include <iostream>
using namespace std;

class MyStack {
private:
  struct Stack {
    int size;
    int top;
    int * next;
  };

  struct Stack *s;

public:

  MyStack(int size) {
    s->size = size;
    s->top = -1;
    s->next = (int *)malloc(s->size * sizeof(int));
  };

  auto isEmpty() -> int {
    if(s->top != -1) {
        cout<< "Stack is not empty Empty"<<endl;
        return 0;
    } else {
        cout<< "Stack is Empty"<<endl;
        return 1;
    }
  };
  auto isFull() -> int {
    if(s->top == s->size) {
        cout<< "Stack is full"<<endl;
        return 0;
    } else {
        cout<< "Stack is not full"<<endl;
        return 1;
    }
  };

  auto push() -> void {
    
  };

};

int main() {
  MyStack stack(20);
  auto ans = stack.isEmpty();
  cout<<ans<<endl;


  return 0;
}