#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int value) : data(value), next(nullptr) {}
};

class ListNode{
  public:
  int data;
  ListNode* nextValue;
  ListNode(int value) : data(value) , nextValue(nullptr) {
    this->data = value;
  }
}

class Stack {
 private:
  Node* top;

 public:
  Stack() : top(nullptr) {}
  void push(int x) {
    Node* newnode = new Node(x);
    newnode->next = top;
    top = newnode;
  }
  int pop() {
    if (isEmpty()) {
      cout << "Cannot Be Overflowed";
      return -1;
    }
  }
  void push(int x) {
    Node* newNode = new Node(x);
    newNode->next = top;
    top = newNode;
    int pop() {
      if (isEmpty()) {
        cout << "Stack underflow" << endl;
        return -1;
      }
      int poppedData = top->data;
      Node* temp = top;
      top = top->next; 
      delete temp;  
      return poppedData;
    }

    int peek() {
      if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
      }
      return top->data;
    }

    // Check if stack is empty
    bool isEmpty() { return top == nullptr; }

    // Display all elements in the stack
    void displayStack() {
      if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
      }
      Node* current = top;
      cout << "Stack elements: ";
      while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
      }
      cout << endl;
    }
    ~Stack() {
      while (!isEmpty()) {
        pop();
      }
    }
  }
};
int main() {
  Stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.displayStack(); 
  cout << "Top element: " << s.peek() << endl;
  s.pop();
  s.displayStack(); 
}
