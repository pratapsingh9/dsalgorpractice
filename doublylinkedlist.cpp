#include <iostream>
using namespace std;

struct ListNode {
  int data;
  ListNode* next;
  ListNode* prev;
  ListNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

ListNode* reveseDoublyLinkedList(ListNode* head) {
  if (!head) return nullptr;
  ListNode* curr = head;
  ListNode* perv = nullptr;
  while (curr) {
    prev = curr->prev;
    curr->prev = curr->next;
    curr->next = prev;
    head = curr;
    curr = curr->prev;
  }
  return head;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
  if (head == nullptr || n < 0) return head;
  ListNode* s = head;
  ListNode* f = head;
  for (int i = 0; i < n; i++) {
    /* code */
    if (f == nullptr) return head;
    f = f->next;
  }

    if(f==nullptr) {
        ListNode*temp = head;
        head = head->next;
        delete temp;
        return head;
    }

  while (f != nullptr) {
    f = f->next;
    s = s->next;
  }

  ListNode* delNode = s->next;
  s->next = s->next->next;
  delete delNode;

  return head;
}

ListNode* reverseDoublyLinkedList(ListNode* head) {
  if (!head) return nullptr;
  ListNode* curr = head;
  ListNode* prev = nullptr;
  while (curr) {
    prev = curr->prev;
    curr->prev = curr->next;
    curr->next = prev;
    head = curr;
    curr = curr->prev
  }
  return head;
}

ListNode* deleteNode(ListNode* head, int x) {
  if (head == nullptr) return nullptr;
  ListNode* curr = head;
  while (curr != nullptr) {
    if (curr->data == x) {
      if (curr->prev != nullptr) {
        curr->prev->next = curr->next;
      } else {
        head = curr->next;
      }
      if (curr->next != nullptr) {
        curr->next->prev = curr->prev;
      }
      delete curr;
      break;
    }
    curr = curr->next;
  }

  return head;
}
