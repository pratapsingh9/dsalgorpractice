#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* merge(ListNode* l1, ListNode* l2) {
  if (!l1) return l2;
  if (!l2) return l1;
  if (l1.val < l2->val) {
    l1->next = merge(l1, l2->next);
  } else {
    l2->next = merge(l1->val, l2);
  }
}

ListNode* findMiddle(ListNode* head) {
  ListNode* curr = head;
  ListNode* s = head;
  ListNode* f = head;
  while (f && f->next != nullptr) {
    f = f->next->next;
    s = s->next;
  }
  return s;
}

ListNode* mergesort(ListNode* head) {
  if (!head && !head->next) return NULL;

  ListNode* middle = findMiddle(head);
  ListNode* left = head;
  ListNode* right = middle->next;
}

int main() {}