#include <iostream>
using namespace std;

// Node structure for the BST
struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    data = val;
    left = right = nullptr;
  }
};
int findCiel(Node* root, int key) {
  int ciel = -1;
  while (root) {
    if (root->data == key) {
      return root->data;
    } else if (root->data > key) {
      ciel = root->data;
      root = root->left;
    } else {
      root = root->right;
    }
  }
  return ciel;
}

int findfloor(Node*root, int key) {
  int floor = -1;
  while(root) {
    if(root->data == key) {
      return root->data;
    }
    else if(root->data < key) {
      floor = root->data;
      root = root->right;
    }else{
      root=root->left;
    }
  }
  return floor;
}

int findFloor(Node* root, int key) {
  int floor = -1;

  while (root) {
    if (root->data == key) {
      return root->data;
    } else if (root->data < key) {
      floor = root->data;
      root = root->right;
    } else {
      root = root->left;
    }
  }

  return floor;
}

// Example usage
int main() {
  // Creating a simple BST
  Node* root = new Node(15);
  root->left = new Node(10);
  root->right = new Node(20);
  root->left->left = new Node(8);
  root->left->right = new Node(12);
  root->right->left = new Node(17);
  root->right->right = new Node(25);

  int key = 18;
  int floorValue = findFloor(root, key);

  if (floorValue == -1)
    cout << "No floor exists for " << key << endl;
  else
    cout << "The floor of " << key << " is " << floorValue << endl;

  return 0;
}
