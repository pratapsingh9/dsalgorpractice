#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partionSolve(int arr[] , int low , int high) {
    int pivot = arr[high];
    int i = low-1;

    for(int j = low; j<high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }

    swap(&arr[i+1],&arr[high]);
    return i+1;
}
 
void quickSort(int arr[] , int low , int high) {
    if(low<high) {
        int it  = partionSolve(arr,low,high);
        quickSort(arr,low,it-1);
        quickSort(arr,it+1,high);
    }
}

void heapify(int arr[], int n, int i) {
  int lagrest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > lagrest) {
    lagrest = left;
  }
  if (right < n && arr[right] > lagrest) {
    lagrest = right;
  }

  if (lagrest != i) {
    swap(&arr[i], &arr[lagrest]);

    heapify(arr, n, lagrest);
  }
}

void heapsort(int arr[], int n) {
  for (int i = n / 2; i >= 0; i--) {
    heapify(arr, n, i);
  }

  for (int i = n - 1; i > 0; i--) {
    swap(&arr[0], &arr[i]);
    heapify(arr, i, 0);
  }
}
int main() {
  int v = 34;
  int *k;
  k = &v;

  printf("name of v is  %d \n", v);
  printf("address of v is  %d", &v);
  printf("k value is %d ", k);
  return 0;
}


struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int height(struct Node *node) {
    if (node == NULL)return 0;
    return node->height;
}

int getBalance(struct Node *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct Node* createNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct Node* rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x;
}

// Left rotation
struct Node* leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y;
}

// Insert function for AVL Tree
struct Node* insert(struct Node* node, int key) {
    // Perform standard BST insertion
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Duplicates are not allowed
        return node;

    // Update height of this ancestor node
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

    // Get the balance factor
    int balance = getBalance(node);

    // If the node is unbalanced, perform rotations

    // Left-Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right-Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left-Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right-Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node; // Return the unchanged node pointer
}

// In-order traversal
void inOrder(struct Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

// Main function
int main() {
    struct Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("In-order traversal of the AVL tree is:\n");
    inOrder(root);

    return 0;
}
