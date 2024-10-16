#include <bits/stdc++.h>
using namespace std;






// stack using linkedList

struct Node {
  int data;
  Node* next;
}

class StackLL {
  Node* top;

 public:
  StackLL() { top = nullptr; }
  void push(int x) {
    Node* newnode = new Node();
    newnode->data = x;
    newnode->next  = top;
    top = newnode;
    cout << "Item added to the stack" << endl;
  }

  int pop() {
    if (top == nullptr) {
      cout << "We cannot do anything" << endl;
      return;
      /* code */
    }
    Node* temp = top;
    top = temp->next;
    int poped = temp->data;
    delete temp;
    return poped;
  }
  int peek() {
    if (top == nullptr) {
      cout << "WE CANNOT DO ANYTHING" << endl;
      return;
    }
    return top->data;
  }
  bool Isempty() { return (top == nullptr); }
}



void reverseStack(stack<int> &s) {
  if(s.empty()) {
    return ;
  }
  int ele = s.top();
  s.pop();
  reverseStack(s);
  s.push(ele);
}

// stack using vector
class Stack {
 private:
  vector<int> arr;
  int top;

 public:
  Stack() { this->top = -1; }

  void push(int x) {
    arr.push_back(x);
    top++;
    cout << "pushed to the stack: " << x << endl;
  }

  int peek() {
    if (!isEmpty()) {
      return arr[top];
    }
    throw runtime_error("Stack is empty");  // Handle empty stack
  }

  int pop() {
    if (!isEmpty()) {
      return arr[top--];
    }
    throw runtime_error("Stack is empty");
  }

  bool isEmpty() { return (top < 0); }
};

int main() {
  Stack s;

  s.push(10);
  s.push(12);
  s.push(14);
  s.push(17);

  cout << "Top element is: " << s.peek() << endl;

  cout << "Popped element is: " << s.pop() << endl;
}