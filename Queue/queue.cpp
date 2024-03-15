#include <cstdlib>
#include <iostream>

using namespace std;

class Queue {

private:
  int SIZEs;

  struct queue {
    int front;
    int rear;
    int *next;
  };

  struct queue *s = (struct queue *)malloc(sizeof(struct queue));

  auto isEmpty() -> bool {
    if (s->front == -1 || s->front > s->rear) {
      return true;
    } else {
      return false;
    }
  };
  auto isFull() -> bool {
    if (s->rear == this->SIZEs - 1) {
      return true;
    } else {
      return false;
    }
  };

public:
  Queue(int SIZE) {
    this->SIZEs = SIZE;
    s->front = -1;
    s->rear = -1;
    s->next = (int *)malloc(this->SIZEs * sizeof(int));
  };

  int enqueue(int val);
  int dequeue();
  int display();
};

auto Queue::enqueue(int val) -> int {
  if (isFull()) {
    cout << "Queue is full" << endl;
    return 0;
  } else {
    if (s->front == -1) {
      s->front = 0;
    }
    s->rear++;
    s->next[s->rear] = val;
    return 1;
  }
};

auto Queue::dequeue() -> int {
  if (isEmpty() == false) {
    int value = s->next[s->front];
    s->front++;
    return value;
  } 
  else {
    cout << "Queue is Empty" << endl;
    return 0;
  }
};

auto Queue::display() -> int {
  if (isEmpty() == true) {
    cout << "Queue is Empty" << endl;
    return 0;
  } else {
    for (int i = 0; i < this->s->rear +1; i++) {
      cout << i + 1 << " -> " << s->next[i] << endl;
    }
    return 1;
  }
};

int main() {
  Queue queue(20);

  queue.enqueue(10);
  queue.enqueue(40);
  queue.enqueue(30);
  queue.enqueue(30);

  int ans = queue.dequeue();
  cout <<ans<<endl;
  
  queue.display();
}