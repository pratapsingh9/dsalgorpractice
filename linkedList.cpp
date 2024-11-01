#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}  // Constructor to initialize a new node
};
class Stack {
private:
    Node* top;  // Pointer to the top of the stack

public:
    // Constructor
    Stack() : top(nullptr) {}
    void push(int x) {
        Node*newnode = new Node(x);
        newnode->next = top;
        top = newnode;
    }

    int pop() {
        if(isEmpty()) {
            cout << "Cannot Be Overflowed" ;
            return -1;
        }
        
    }
    // Push operation
    void push(int x) {
        Node* newNode = new Node(x);  // Create a new node
        newNode->next = top;          // Point new node to the current top
        top = newNode;                // Update top to the new node
    }

    // Pop operation
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return -1;  // Return -1 to indicate an error
        }
        int poppedData = top->data;
        Node* temp = top;
        top = top->next;  // Move top to the next node
        delete temp;      // Delete the old top node
        return poppedData;
    }

    // Peek operation
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

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

    // Destructor to free all nodes
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.displayStack();   // Display stack contents
    cout << "Top element: " << s.peek() << endl;
    s.pop();
    s.displayStack();   // Display stack contents after popping
}
