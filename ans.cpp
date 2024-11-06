#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reveseListWithStack(ListNode* head) {
  if (!head) return nullptr;
  stack<ListNode*> st;

  ListNode* curr = head;

  while (curr != nullptr) {
    st.push(curr);
    curr = curr->next;
  }
  ListNode* newhead = st.top();
  st.pop();
  curr = newhead;

  while (!st.empty()) {
    curr->next = st.top();
    st.pop();
    curr = curr->next;
  }
  curr->next = nullptr;
  return newhead;
}

ListNode* reverseList(ListNode* head) {
  if (!head) {
    /* code */
    return nullptr;
  }

  ListNode* curr = head;
  ListNode* prev = nullptr;
  while (curr != nullptr) {
    /* code */
    ListNode* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

void reorderList(ListNode* head) {
  ListNode* f = head;
  ListNode* s = head;
  while (f != nullptr && f->next) {
    s = s->next;
    f = f->next->next;
  }

  ListNode* rev = findMiddle(s);
  ListNode* curr = head;

  while (rev->next != nullptr) {
    ListNode* curtemp = curr->next;
    ListNode* revTemp = rev->next;
    curr->next = rev;
    rev->next = curtemp;
    curr = curtemp;
    rev = revTemp;
  }
}
ListNode* middle(ListNode* head) {
  ListNode* slow = head;
  ListNode* fast = head;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

ListNode* reverse(ListNode* head) {
  ListNode* prev = nullptr;
  ListNode* curr = head;
  while (curr != nullptr) {
    ListNode* nextTemp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextTemp;
  }
  return prev;
}

bool isPalindrome(ListNode* head) {
  if (head == NULL && head->next == NULL) {
    return true;
  }

  ListNode* middle = middle(head);
  ListNode* revMiddle = reverse(middle);

  ListNode* p1 = head;
  ListNode* p2 = revMiddle;

  bool res = false;
  while (p2 != nullptr) {
    if (p1->val != p2->val) {
      return false;
    }
    p2 = p2->next;
    p1 = p1->next;
  }
  return res;
}

ListNode* detectcycle(ListNode* head) {
  ListNode* s = head;
  ListNode* f = head;

  while (f && f->next) {
    s = s->next;
    f = f->next->next;
    if (s == f) {
      s = head;
      while (s != f) {
        s = s->next;
        f = f->next;
      }
      return s;
    }
  }
  return nullptr;
}

bool LinkedListCycle(ListNode* head) {
  ListNode* f = head;
  ListNode* s = head;

  while (f && f->next) {
    f = f->next;
    if (f != nullptr) {
      f = f->next;
    }
    s = s->next;
    if (f == s) {
      return true;
    }
  }
  return false;
}

void reoderList(ListNode* head) {
  ListNode* f = head;
  ListNode* s = head;
  while (f && f->next) {
    s = s->next;
    f = f->next->next;
  }
  ListNode* resv = reverseList(s);
  ListNode* curr = head;
  while (resv->next != nullptr) {
    ListNode* curtemp = curr->next;
    ListNode* reverseTemp = resv->next;
    curr->next = resv;
    resv->next = curtemp;
    curr = curtemp;
    resv = reverseTemp;
  }
}

ListNode* reverseList(ListNode* head) {
  if (!head || !head->next) {
    return head;
  }
  ListNode* newHead = reverseList(head->next);
  head->next->next = head;
  head->next = nullptr;
  return newHead;
}

ListNode* constructDoublyLl(vector<int>& arr) {
  if (arr.empty()) return nullptr;
  ListNode* head = new ListNode(arr[0]);
  ListNode* curr = head;
  for (int i = 0; i < arr.size(); i++) {
    /* code */
    ListNode* newnode = new ListNode(arr[i]);
    curr->next = newnode;
    newnode->prev = curr;
    curr = newnode;
  }
  return head;
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

ListNode* removentheNode(ListNode* head, int n) {
  ListNode* dummy = new ListNode(0);
  dummy->next = head;
  ListNode* f = dummy;
  ListNode* s = dummy;

  for (int i = 0; i <= n; i++) {
    if (f == nullptr) return head;
    f = f->next;
  }
  while (f != nullptr) {
    f = f->next;
    s = s->next;
  }
  ListNode* delNode = s->next;
  s->next = s->next->next;
  delete delNode;
  ListNode* newhead = dummy->next;
  delete dummy;
  return newhead;
}

ListNode* addtwoNumber(ListNode* l1, ListNode* l2) {
  ListNode* dummy = new ListNode(0);
  ListNode* curr = dummy;
  int carr = 0;
  while (l1 || l2) {
    int val1 = (l1 != nullptr) ? l1->val : 0;
    int val2 = (l2 != nullptr) ? l2->val : 0;

    int ans = val1 + val2;
    curr->next = new ListNode(ans % 10);
    carr = ans / 10;
    if (l1) {
      l1 = l1->next;
    }
    if (l2) {
      l2 = l2->next;
    }
    curr = curr->next;
  }
  if(carr > 0) {
    curr->next = new ListNode(carr);
  } 

  return dummy->next;
}