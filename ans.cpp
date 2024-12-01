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
  if (carr > 0) {
    curr->next = new ListNode(carr);
  }

  return dummy->next;
}

ListNode* evenandodd(ListNode* head) {
  ListNode* dummy = new ListNode(10);
  ListNode* dummy2 = new ListNode(0);

  ListNode* f = dummy;
  ListNode* s = dummy2;

  while (head != nullptr) {
    if (head->val % 2 == 0) {
      f->next = head;
      f = f->next;
    } else {
      s->next = head;
      s = s->next;
    }
    head = head->next;
  }

  s->next = nullptr;
  f->next = s->next;

  return dummy->next;
}

ListNode* reverseList(ListNode* head) {
  ListNode* prev = nullptr;
  ListNode* current = head;
  ListNode* next = nullptr;

  while (current != nullptr) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  return prev;
}

ListNode* subtractLinkedLists(ListNode* l1, ListNode* l2) {
  l1 = reverse(l1);
  l2 = reverse(l2);

  ListNode* res = nullptr;
  ListNode* prev = nullptr;
  int borrow = 0;

  while (l1 != nullptr || l2 != nullptr || borrow != 0) {
    int val1 = (l1 != nullptr) ? l1->val : 0;
    int val2 = (l2 != nullptr) ? l2->val : 0;

    int diff = val1 - val2 - borrow;

    if (diff < 0) {
      diff += 10
    }
  }
}

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; }

    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)>
        pq(cmp);

    for (ListNode* list : lists) {
      if (list) {
        pq.push(list);
      }
    }
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    // dummy->next = pq.top();

    while (!pq.empty()) {
      ListNode* node = pq.to
    }
  }
};

class Solution {
 public:
  int findChampion(int n, vector<vector<int>>& edges) {
    if (edges.empty()) return -1;
    // vector<vector<int>> edges(n);
    vector<bool> indegree(n, 0);
    for (auto edge : edges) {
      indegree[v] = false;
    }
    if (count(indegree.begin(), indegree.end(), false) == 1) {
      return find(indegree.begin(), indegree.end(), false) - indegree.begin();
    } else {
      return -1;
    }
  }
};

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    vector<vector<int>> result;
    int n = intervals.size();
    int i = 0;
    while (i < n && intervals[i][1] < newInterval[0]) {
      result.push_back(intervals[i]);
      i++;
    }

    while (i < n && intervals[i][0] <= newInterval[1]) {
      newInterval[0] = min(newInterval[0], intervals[i][0]);
      newInterval[1] = max(newInterval[1], intervals[i][1]);
      i++;
    }
    result.push_back(newInterval);

    while (i < n) {
      result.push_back(intervals[i]);
      i++;
    }
    return result;
  }
};

class Solution {
 public:
  int minTimeToType(string word) {
    int currpostiton = 'a';
    int timer = 0;
    for (char c : word) {
      int clockWise = abs(c - currpostiton);
      int counterClockwies = 26 - clockWise;
      timer += min(clockWise, counterClockwies);
      currpostiton = c;
    }
    timer += word.size();
    return timer;
  }
};

class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int ans = 0;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] <= nums[i - 1]) {
        ans += nums[i - 1] + 1 - nums[i];
      }
    }
    return ans;
  }
};

class Solution {
 public:
  int to_minutes(string& time) {
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    return hours * 60 + minutes;
  }

  int convertTime(string current, string correct) {
    int currentTime = to_minutes(current);
    int correctTime = to_minutes(correct);
    vector<int> time_intervals = {60, 15, 5, 1};
    int diff = correctTime - currentTime;
    int moves = 0;
    for (int interval : time_intervals) {
      moves += diff / interval;
      diff %= interval;
    }

    return moves;
  }
};

class Solution {
 public:
  int giveDiffrence(string current, string correct) {
    int currHour = (current[0] - '0') * 10 + (current[1] - '0');
    int currMinute = (current[3] - '0') * 10 + (current[4] - '0');
    int correctHour = (correct[0] - '0') * 10 + (correct[1] - '0');
    int correctMinute = (correct[3] - '0') * 10 + (correct[4] - '0');

    return (correctHour * 60 + correctMinute) - (currHour * 60 + currMinute);
  }
  int convertTime(string current, string correct) {
    int diff = giveDiffrence(current, correct);
    vector<int> operation = {60, 15, 5, 1};
    int totalOpeation = 0;
    for (int operate : operation) {
      totalOpeation += diff / operate;
      diff %= operate;
    }
    return totalOpeation;
  }
};

class Solution {
 public:
  int minCostToMoveChips(vector<int>& position) {
    int evenCount = 0;
    int oddCount = 0;
    for (int it : position) {
      if (it % 2 == 0) {
        evenCount++;
      } else {
        oddCount++;
      }
    }
    return min(evenCount, oddCount);
  }
};

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int n = nums.size();
    int maxy = 0;
    for (int i = 0; i < n; i++) {
      if (i > maxy) {
        return false;
      }
      maxy = max(maxy, i + nums[i]);
      if (maxy >= n - 1) {
        return true;
      }
    }
    return false;
  }
};

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int chinneseRemainder(vector<int>& nums, vector<int> rems) {
  int prod = 1;
  int result = 0;
  for (int n : nums) prod *= n;

  for (int i = 0; i < nums.size(); i++) {
  }
}

void solved() {
  int n, k;
  cin >> n >> k;
  if (k <= (n + 1) / 2) {
  }
}
class Solution {
 public:
  typedef pair<int, int> P;
  vector<string> findRelativeRanks(vector<int>& score) {
    vector<string> answer(score.size(), "");
    vector<string> prize = {"Gold Medal", "Silver Medal", "Bronze Medal"};

    priority_queue<P> pq;
    for (int i = 0; i < score.size(); i++) {
      pq.push(make_pair(score[i], i));
    }
    int rank = 0;
    while (!pq.empty()) {
      int index = pq.top().second;
      pq.pop();
      if (rank < 3) {
        answer[index] = prize[rank];
      } else {
        answer[index] = to_string(rank + 1);
      }
      rank++;
    }

    return answer;
  }
};

class Solution {
 public:
  long long pickGifts(vector<int>& gifts, int k) {
    long long response = 0;
    priority_queue<int> pq(gifts.begin(), gifts.end());
    while (k--) {
      int val = pq.top();
      pq.pop();
      pq.push(sqrt(val));
    }
    while (!pq.empty()) {
      response += pq.top();
      pq.pop();
    }
    return response;
  }
};

class Solution {
 public:
  int largestInteger(int num) {
    priority_queue<int> evenHeap;
    priority_queue<int> oddHeap;

    string n = to_string(num);
    for (int i = 0; i < n.size(); i++) {
      int value = n[i] - '0';
      if (i % 2 == 0) {
        evenHeap.push(value);
      } else {
        oddHeap.push(value);
      }
    }
    string result = "";
    for (int i = 0; i < n.size(); i++) {
      if (i % 2 == 0) {
        result += to_string(evenHeap.top());
        evenHeap.pop();
      } else
        [result += to_string(oddHeap.top()); oddHeap.pop();]
    }
    return stoi(result);
  }
};

class Solution {
 public:
  int largestInteger(int num) {
    string number = to_string(num);
    vector<int> even, odd;
    for (char c : number) {
      int digit = c - '0';
      if (digit % 2 == 0) {
        even.push_back(digit);
      } else {
        odd.push_back(digit);
      }
    }
    sort(even.rbegin(), even.rend());
    sort(odd.rbegin(), odd.rend());

    int evenIndex = 0, oddIndex = 0;
    for (int i = 0; i < number.size(); i++) {
      int digit = number[i] - '0';
      if (digit % 2 == 0) {
        number[i] = even[evenIndex++] + '0';
      } else {
        number[i] = odd[oddIndex++] + '0';
      }
    }
    return stoi(number);
  }
};

class Solution {
 public:
  int countNegatives(vector<vector<int>>& grid) {
    int answer = 0;
    for (int i = 0; i < grid.size(); i++) {
      /* code */
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] < 0) {
          answer++;
        }
      }
    }
    return answer;
  }
};

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    int row = 0;
    int cols = n - 1;

    while (row < m && cols >= 0) {
      if (matrix[row][cols] == target)
        return true;
      else if (matrix[row][cols] < target) {
        row++;
      } else
        cols--;
    }
    return false;
  }
};

class Solution {
 public:
  int bfs(int n, unordered_map<int, vector<int>>& graph) {
    vector<int> distance(n, INT_MAX);
    queue<int> q;
    distance[0] = 0;
    q.push(0);
    while (!q.empty()) {
      int node = q.front();
      q.pop();

      for (int neighbour : graph[node]) {
        if (distance[neighbour] > distance[node] + 1) {
          distance[neighbour] = distance[node] + 1;
          q.push(neighbour);
        }
      }
    }
    return distance[n - 1];
  }
  vector<int> shortestDistanceAfterQueries(int n,
                                           vector<vector<int>>& queries) {
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < n - 1; i++) {
      /* code */
      graph[i].push_back(i + 1);
    }
    vector<int> result;

    for (const auto& query : queries) {
      int u = query[0];
      int v = query[1];

      graph[u].push_back(v);
      result.push_back(bfs(n, graph));
    }
    return result;
  }
};

class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int k) {
    vector<vector<pair<int, int>>> graph(n);
    for (const auto& flight : flights) {
      int u = flight[0];
      int v = flight[1];
      int cost = flight[2];

      graph[u].push_back({v, cost});
    }

    int minCost = INT_MAX;

    vector<int> distance(n, INT_MAX);
    distance[src] = 0;
    queue<vector<int>> q;

    q.push({0, src, 0});
    while (!q.empty()) {
      auto current = q.front();
      q.pop();
      int currentNode = current[1];
      int stops = current[0];
      int totalCost = current[2];

      if (stops > k) continue;
      for (auto neighbour : graph[currentNode]) {
        int next = neighbour.first;
        int movingCost = neighbour.second;

        int newCost = movingCost + totalCost;

        if (newCost < distance[next]) {
          distance[next] = newCost;
        }
        if (next == dst) {
          minCost = min(minCost, newCost);
        }

        q.push({stops + 1, next, newCost});
      }
    }
    return minCost == INT_MAX ? -1 : minCost;
  }
};

class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] == mid) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return low;
  }
};

class Solution {
 public:
  int findKthPositive(vector<int>& arr, int k) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
      int mid = (high + low) / 2;

      int missingNumber = arr[mid] - (mid + 1);

      if (missingNumber > k) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return low + k;
  }
};

class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    sort(nums.begin(), nums.end());
    while (low <= high) {
      int mid = (high + low) / 2;
      int count = 0;
      for (int num : nums) {
        if (num <= mid) count++;
      }
      if (count > mid) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    return low;
  }
};

class Solution {
 public:
  vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    int left = 0, right = cols - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      int maxRowIndex = 0;
      for (int i = 0; i < rows; i++) {
        if (mat[i][mid] > mat[maxRowIndex][mid]) {
          maxRowIndex = i;
        }
      }

      bool isTopSmaller = (mid == 0 || mat[mid][maxRowIndex])
    }
  }
};

class Solution {
 public:
  char nonRepeatingChar(string& s) {
    unordered_map<char, int> mp;
    for (char c : s) {
      mp[c]++
    }

    for (char c : s) {
      if (mp[c] == 1) {
        return c;
      }
    }
    return '\0';
  }
};

#include <vector>
using namespace std;


