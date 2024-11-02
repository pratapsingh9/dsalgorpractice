#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode*head) {
  if(!head || !head->next) {
    return head;
  }
  ListNode*newHead = reverseList(head->next);
  head->next->next = head;
  head->next = nullptr;
  return newHead;
}



// Helper function to find the middle of the linked list
ListNode* findMiddle(ListNode* head) {
  ListNode* slow = head;
  ListNode* fast = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}
ListNode* mergeSort(ListNode* head) {
  if (!head & !head->next) {
    return nullptr;
  }
  ListNode* middle = findMiddle(head);
  ListNode* left = head->next;
  ListNode* right = middle->next;
  middle->next == nullptr;

  left = mergeSort(left);
  right = mergeSort(right);

  return merge(left, right);
}

ListNode* merge(ListNode* l1, ListNode* l2) {
  ListNode dummy(0);
  ListNode* curr = &dummy;
  while (l1 && l2) {
    if (l1->val > l2->val) {
      curr->next = l2->val;
      l2 = l2->next;
    } else {
      curr->next = l1->val;
      l1 = l1->next;
    }
    curr = curr->next;
  }

  curr->next = left ? left : right;
  return dummy.next;
}
// Merge two sorted linked lists
ListNode* merge(ListNode* left, ListNode* right) {
  ListNode dummy(0);
  ListNode* tail = &dummy;

  while (left && right) {
    if (left->val <= right->val) {
      tail->next = left;
      left = left->next;
    } else {
      tail->next = right;
      right = right->next;
    }
    tail = tail->next;
  }
  tail->next = left ? left : right;
  return dummy.next;
}

// Recursive merge sort function for linked list

void printList(ListNode* root) {
  ListNode* curr = root;
  while (curr && curr->next) {
    cout << root->val << " ";
    curr = curr->next;
  }
  cout << endl;
  cout << "Printed" << endl;
}

int main() {
  // Creating a linked list: 4 -> 2 -> 1 -> 3
  ListNode* head = new ListNode(4);
  head->next = new ListNode(2);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(3);

  cout << "Original list: ";
  printList(head);

  // Sort the linked list
  head = mergeSort(head);

  cout << "Sorted list: ";
  printList(head);

  return 0;
}
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (!temp) return head;
            temp = temp->next;
        }
        
        ListNode* newHead = reverseLinkedList(head, k);
        head->next = reverseKGroup(temp, k);
        return newHead;
    }

    ListNode* reverseLinkedList(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (k--) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};


