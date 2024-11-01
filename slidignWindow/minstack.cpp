#include <bits/stdc++.h>
using namespace std;

class Node {
  int data;
  Node* next;
  Node(int value) : data(value), next(nullptr) {}
}

class Stack {
  Node* top;

 public:
  Stack() : top(nullptr) {}
  ~Stack() {
    while (top != nullptr) {
      pop();
    }
  }
  bool isEmpty() { return top == nullptr; }
  void push(int x) {
    Node* newval = new Node(x);
    newval->next = top;
    top = newval;
  }
  int pop() {
    if (isEmpty()) {
      cout << "Cannot do this" << endl;
      return -1;
    }
    Node* temp = top;
    int val = temp->data;
    top = top->next;
    delete temp;
    return val;
  }
  int peek() {
    if (isEmpty()) {
      cout << "Not able to get the peak stack not supports";
      return -1;
    }
    return top->data;
  }
  void display() {
    if (isEmpty()) {
      /* code */
      cout << "overflowd";
      return;
    }
    Node* curr = top;
    while (top != nullptr) {
      cout << top->data << " ";
      top = top->next;
    }
    cout << endl;
  }
}

int main() {
  return 0;
}