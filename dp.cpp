#include <iostream>
using namespace std;

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

int findfloor(Node* root, int key) {
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
