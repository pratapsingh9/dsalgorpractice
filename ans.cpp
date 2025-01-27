#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseLL(ListNode* head) {
  if (!head || !head->next) {
    return head;
  }
}

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
    return nullptr;
  }
  ListNode* curr = head;
  ListNode* prev = nullptr;
  while (curr != nullptr) {
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
  ListNode* head = new ListNode(4);
  head->next = new ListNode(2);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(3);
  cout << "Original list: ";
  printList(head);
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

int numberOfSwap(string input) {
  int n = input.size();
  int zeroCount = count(input.begin(), input.end(), 0);
  int oneCount = n - zeroCount;
  if (zeroCount % 2 == 0 && oneCount % 2 == 0) {
    return -1;
  }
  int swaps = 0, left = 0, right = n - 1;
  while (left < right) {
    if (s[left] == s[right]) {
      left++;
      right--;
    } else {
      int k = right;
    }
  }
  return swaps;
}
class Solution {
 public:
  bool canMakeSubsequence(string str1, string str2) {
    int i = 0, j = 0;

    while (i < str1.size() && j < str2.size()) {
      if (str1[i] == str2[j]) {
        j++;
      } else if ((str1[i] - 'a' + 1) % 26 + 'a' == str2[j]) {
        j++;
      }
      i++;
    }

    return j == str2.size();
  }
};

bool areRotations(string& s1, string& s2) {
  if (s1.size() != s2.size()) {
    return false;
  }
  int n = s1.length();
  string temp = s1;
  for (int i = 0; i < n; i++) {
    char first = temp[0];
    temp = temp.substr(1) + first;
    if (temp == s2) return true;
  }
  return false;
}

class Solution {
 public:
  int missingInteger(vector<int>& nums) {
    int sumPrefix = nums[0];
    for (size_t i = 0; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1] + 1) {
        sumPrefix += nums[i];
      } else {
        break;
      }
    }
    unordered_set<int> set(nums.begin(), nums.end());
    int x = sumPrefix;
    while (set.count(x)) {
      x++;
    }
    return x;
  }
};

void insertAtKth(int value, int k) {
  Node* new_node = new Node(value);
  if (k == 0) {
    insertAtHead(value);
    return;
  }
  Node* temp = head;
  int count = 1;
  while (temp != NULL && count < k - 1) {
    temp = temp->next;
    count++;
  }
  // check kar k null toh  nahi h code m
  new_node->next = temp->next;
  temp->next = new_node;
  new_node->prev = temp;
}

class Solution {
 public:
  ListNode* insertionSortList(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* sorted = nullptr;

    while (head) {
      ListNode* current = head;
      head = head->next;
      if (!sorted || sorted->val >= current->val) {
        current->next = sorted;
        sorted = current;
      } else {
        ListNode* temp = sorted;
        while (temp->next && temp->next->val < current->val) {
          temp = temp->next;
        }
        current->next = temp->next;
        temp->next = current;
      }
    }

    return sorted;
  }
};

class Solution {
 public:
  void dfs(vector<vector<char>>& board, int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'X') return;
    board[r][c] = '.';
    dfs(board, r + 1, c);
    dfs(board, r, c + 1);
    dfs(board, r - 1, c);
    dfs(board, r, c - 1);
  }

  int countBattleships(vector<vector<char>>& board) {
    int rows = board.size();
    int cols = board[0].size();
    int count = 0;

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (board[i][j] == 'X') {
          count++;
          dfs(board, i, j);
        }
      }
    }
    return count;
  }
};

class Solution {
 public:
  unordered_map<int, int> mp;
  void solve(TreeNode* root) {
    if (root == nullptr) {
      return;
    }
    solve(root->left);
    mp[root->val] = mp[root->val]++;
    solve(root->right);
  }
  vector<int> findMode(TreeNode* root) {
    solve(root);
    int maxfreq = 0;
  }
};

class Solution {
 public:
  bool canBeValid(string s, string locked) {
    int n = s.size();
    if (n % 2 != 0) return false;

    int minOpen = 0, maxClose = 0;
    for (int i = 0; i < n; i++) {
      maxClose++;
      minOpen = min(0, minOpen - 1);
    }
  }
};
class Solution {
 public:
  TreeNode* reverseOddLevels(TreeNode* root) {
    bool isOddLevel = false;
    queue<TreeNode*> q;
    q.push(root);
    vector<int> ans;
    while (!q.empty()) {
      int size = q.size();
      vector<TreeNode*> vec;
      for (int i = 0; i < size; i++) {
        TreeNode* node = q.front();
        q.pop();

        vec.push_back(node);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }

      if (isOddLevel) {
        int left = 0, right = vec.size() - 1;
        while (left < right) {
          swap(vec[left]->val, vec[right]->val);
          left++;
          right--;
        }
      }
      isOddLevel = !isOddLevel;
    }
    return root;
  }
};

class Solution {
 public:
  void dfs(TreeNode* left, TreeNode* right, int level) {
    if (!left || !right) return;

    if (level % 2 == 0) {
      swap(left->val, right->val);
    }
    dfs(left->left, right->right, level + 1);
    dfs(left->right, right->left, level + 1);
  }
  TreeNode* reverseOddLevels(TreeNode* root) {
    if (!root) return nullptr;
    dfs(root->left, root->right, 1);
    return root;
  }
};

class Solution {
 public:
  int minReorder(int n, vector<vector<int>>& connections) {
    unordered_map<int, vector<pair<int, int>>> adj;
    for (auto& con : connections) {
      adj[con[0]].push_back({con[1], 1});
      adj[con[1]].push_back({con[0], 0});
    }

    vector<bool> visited(n, false);
    int result = 0;
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
    }
    for (auto it : adj) {
      int neightbours = it.first;
      int isOutgoing = it.second;
      if (!visited[neightbours]) {
        visited[neightbours] = true;
        result += isOutgoing;
        q.push(neightbours);
      }
    }
    return result;
  }
};

class Solution {
 public:
  int main() { cout << "yup" }
}

class Solution {
 public:
  int minimumOperations(vector<int>& nums, int start, int goal) {
    if (goal < 0 || goal > 1000) return -1;
    queue<pair<int, int>> q;
    unordered_set<int> visited;
    q.push({start, 0});
    visited.insert(start);
    while (!q.empty()) {
      int x = q.front().first;
      int operations = q.front().second;
      if (x == goal) return operations;
      for (int num : nums) {
        vector<int> vals = {x - num, x + num, x ^ num};
        for (int next : vals) {
          if (next >= 0 && next <= 1000 &&
              visited.find(next) == visited.end()) {
            q.push({next, operations + 1});
            visited.insert(next);
          }
        }
      }
    }
    return -1;
  }
};

class Solution {
 public:
  int minimumOperationsToMakeEqual(int x, int y) {
    queue<pair<int, int>> q;
    unordered_set<int> visited;
    q.push({x, 0});
    visited.insert(x);
    while (!q.empty()) {
      int x = q.front().first;
      int ops = q.front().second;
      if (x == y) return ops;
      vector<int> possiblites = {x / 11, x / 5, x - 1, x + 1};
      for (int values : possiblites) {
        if (values >= 0 && visited.find(values) == visited.end()) {
          if (values == y) return ops + 1;
          q.push({visited, ops + 1});
          visited.insert(values);
        }
      }
    }
    return -1;
  }
};

class Solution {
 public:
  bool canReach(vector<int>& arr, int start) {
    int n = arr.size();
    queue<int> q;
    unordered_set<int> visited;
    q.push(start);
    visited.insert(start);
    while (!q.empty()) {
      int indx = q.front();
      q.pop();
      if (arr[indx] == 0) return true;
      int forward = indx + arr[indx];
      int backward = indx - arr[indx];
      if (forward < n && visited.find(forward) == visited.end()) {
        q.push(forward);
        visited.insert(forward);
      }
      if (backward >= 0 && visited.find(backward) == visited.end()) {
        q.push(backward);
        visited.insert(backward);
      }
    }
    return false;
  }
};

class Solution {
 public:
  static bool isVowel(char c) {
    static const unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    return vowels.find(c) != vowels.end();
  }
  vector<int> vowelStrings(vector<string>& words,
                           vector<vector<int>>& queries) {
    vector<int> answer;
    vector<int> prefix(words.size(), 0);
    for (int i = 0; i < words.size(); i++) {
      const string& word = words[i];
      if (isVowel(word[0]) && isVowel(word.back())) {
        prefix[i] = 1;
      }
    }

    for (int i = 1; i < words.size(); i++) {
      prefix[i] += prefix[i - 1];
    }

    for (auto& query : queries) {
      int left = query[0];
      int right = query[1];
      int value = prefix[right];
      if (left > 0) {
        value -= prefix[left - 1];
      }
      answer.push_back(value);
    }
    return answer;
  }
};

class Solution {
 public:
  bool divideArray(vector<int>& nums) {
    if (nums.size() % 2 != 0) return false;

    int divied = nums.size() / 2;
    unordered_map<int, int> mp;

    for (int n : nums) {
      mp[n]++;
    }

    for (auto it : mp) {
      if (it.second % 2 != 0) return false;
    }

    return true;
  }
};

class Solution {
 public:
  bool canBeValid(string s, string locked) {
    int n = s.size();
    if (n % 2 != 0) return false;
    int balance = 0, opened = 0;

    for (int i = 0; i < n; i++) {
      if (locked[i] == '1') {
        balance +=
      }
    }
  }
};

class Solution {
 public:
  vector<int> resultArray(vector<int>& nums) {
    vector<int> result;
    int last1 = -1, last2 = -1;
    result.push_back(nums[0]);
    last1 = 0;
    result.push_back(nums[1]);
    last2 = 1;

    for (int i = 2; i < nums.size(); i++) {
      if (result[last1] > result[last2]) {
        result.push_back(nums[i]);
        last1 = result.size() - 1;
      } else {
        result.push_back(nums[i]);
        last2 = result.size() - 1;
      }
    }
    return result;
  }
};

class Solution {
 public:
  bool canConstruct(string s, int k) {
    if (k > s.size()) return false;
    int odd = 0, i = 0;
    sort(s.begin(), s.end());
    while (i < s.size()) {
      int count = 0;
      char current = s[i];
      while (i < s.size() && s[i] == current) {
        count++;
        i++;
      }
      if (count % 2 != 0) odd++;
    }
    return odd <= k;
  }
};

class Solution {
 public:
  void dfs(TreeNode* node, int index, int width, int maxy) {
    if (!node) return;
    if (width == lindex.size()) }
  int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    int maxy = 0;
    vector<int> lindex;
    dfs(root, 0, 0, maxy);
    return maxy;
  }
};

class Solution {
 public:
  int minimumLength(string s) {
    int n = s.size();
    vector<int> charFreq(26, 0);
    for (int i = 0; i < n; i++) {
      charFreq[s[i] - 'a']++;
      if (charFreq[s[i] - 'a'] == 3) {
        charFreq[s[i] - 'a'] -= 2;
      }
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
      ans += charFreq[i];
    }

    return ans;
  }
};
class Solution {
 public:
  int minimumLength(string s) {
    int n = s.size();
    vector<int> charFreq(26, 0);
    for (int i = 0; i < n; i++) {
      charFreq[s[i] - 'a']++;
    }
    int result = 0;
    for (int i = 0; i < 26; i++) {
      if (charFreq[i] == 0) continue;

      if (charFreq[i] % 2 == 0) result += 2;
      if (charFreq[i] % 2 != 0) result += 1;
    }
    return result;
  }
};

class Solution {
 public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    unordered_map<int, vector<int>> diagonals;
    int row = mat.size(), cols = mat[0].size();
    for (int i = 0; i < row; i++) {
      /* code */
      for (int j = 0; j < cols; j++) {
        /* code */
        diagonals[i - j].push_back(mat[i][j]);
      }
    }

    for (auto& diag : diagonals) {
      sort(diag.second.begin(), diag.second.end());
    }

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < cols; j++) {
        int diagonal = i - j;

        mat[i][j] = diagonals[diagonal].back();
      }
    }
  }
};

class Solution {
 public:
  void buildGraph(TreeNode* node, TreeNode* parent,
                  unordered_map<int, vector<int>>& graph) {
    if (!node) return;

    if (parent) {
      graph[node->val].push_back(parent->val);
      graph[parent->val].push_back(node->val);
    }
    buildGraph(node->left, node, graph);
    buildGraph(node->right, node, graph);
  }
  int amountOfTime(TreeNode* root, int start) {
    unordered_map<int, vector<int>> graph;
    buildGraph(root, nullptr, graph);

    unordered_set<int> visited;

    queue<int> q;
    q.push(start);
    visited.insert(start);
    int time = 0;

    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        int node = q.front();
        q.pop();
        for (int neighbour : graph[node]) {
          if (visited.count(neighbour) == 0) {
            visited.insert(neighbour);
            q.push(neighbour);
          }
        }
      }
      if (!q.empty()) time++;
    }
    return time;
  }
};

class Solution {
 public:
  int findSecondMinimumValue(TreeNode* root) {
    if (!root || (!root->left || !root->right)) {
      return 0;
    }

    return solve(root, root->val);
  }

  int solve(TreeNode* root, int nodevalue) {
    if (!root) return -1;

    if (node->val > nodevalue) {
      return node->val;
    }

    int left = solve(root->left, nodevalue);
    int right = solve(root->right, nodevalue);

    if (left == -1) return right;
    if (right == -1) return left;

    return min(left, right);
  }
};

class Solution {
 public:
  int deepestLeavesSum(TreeNode* root) {
    if (!root) return 0;

    queue<TreeNode*> q;
    q.push(root);
    int sum = 0;
    while (!q.empty()) {
      int levelsize = q.size();
      sum = 0;
      for (size_t i = 0; i < levelsize; i++) {
        /* code */
        TreeNode* node = q.front();
        q.pop();
        sum += node->val;

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
    }

    return sum;
  }
};

class Solution {
 public:
  void dfs(TreeNode* root, int depth, int maxd, int sum) {
    if (!root) return;
  }
  int deepestLeavesSum(TreeNode* root) {
    int maxd = -1;
    int sum = 0;
    dfs(root, 0, maxd, sum);
    return sum;
  }
};

// Method 2 : Optimized Brute force
class Solution {
 public:
  vector<int> zigzagTraversal(vector<vector<int>>& grid) {
    vector<int> result;
    bool goRight = true;

    for (int r = 0; r < grid.size(); r++) {
      if (goRight) {
        for (int c = 0; c < grid[r].size(); c += 2)
          result.push_back(grid[r][c]);
      } else {
        int start =
            grid[r].size() % 2 == 0 ? grid[r].size() - 1 : grid[r].size() - 2;
        for (int c = start; c >= 0; c -= 2) {
          result.push_back(grid[r][c]);
        }
      }
      goRight = !goRight;
    }
    return result;
  }
};

class Solution {
 public:
  int mod = 1000000007;
  void solve(int maxrow , int maxC,int i , int j , int &maxy ,vector<vector<int>>& grid ) {
    if(i>=maxrow || j>=maxC) return ;

    if(i==maxrow-1 && j==maxC-1) {
      maxy=max(maxy,grid[i][j]);
      return ;
    } 

    if()
  }
  int maxProductPath(vector<vector<int>>& grid) {
    int row = grid.size();
    int cols = grid[0].size();
    long long maxy = -1;
    solve(row,cols,0,0,maxy,grid);
    return maxy%mod;
  }
};

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
      int ans = INT_MAX;
        for(int i = 0; i<grid.size(); i++) {
          for(int j = 0; grid[0].size();j++){
            int miny = INT_MAX;
            if(i==0 && j==0) continue;
            if(i!=0) miny =min(miny,grid[i-1][j]);
            if(j!=0) miny=min(miny,grid[i][j-1]);
            ans=max(ans,grid[i][j]-min);
            grid[i][j]=min(grid[i][j],min);
          }
        }
        return ans;
    }
};


class Solution {
public:
    int MOD = 100000009;
    int minMaxSums(vector<int>& nums, int k) {
      int sum = 0 ;

      return sum;
    }
};


void sieveof(int n) {
  vector<bool> isPrime(n+1,true);
  isPrime[0]=false;
  isPrime[1]=false;

  for(int i  =2; i*i <= n; i++) {
    if(isPrime[i]=true) {
      for(int j = i*i; j<=n; j++) {
        isPrime[j]=false;
      }
    }
  }
}


class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long result_ans = LLONG_MAX;
        long long row1sum = accumulate(grid[0].begin(),grid[0].end(),0LL);
        long long row2sum =  0;

        for(int robotMove = 0 ; robotMove<grid[0].size(); robotMove++) {
          // jab robot aage badega toh ye wala robot 2 lelega
          row1sum -= grid[0][i];
          result_ans = min(result_ans,max(row1sum,row2sum));

          row2sum += grid[1][i]; 
        }
        return result_ans;
    }
};


class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        
        int target_mod = total_sum % p;
        if (target_mod == 0) return 0; 

        unordered_map<int, int> prefix_mod_map; /
        prefix_mod_map[0] = -1; // Initialize with a dummy prefix
        int min_len = nums.size();
        long long prefix_sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            prefix_sum += nums[i];
            int current_mod = prefix_sum % p;
            int needed_mod = (current_mod - target_mod + p) % p;
            if (prefix_mod_map.find(needed_mod) != prefix_mod_map.end()) {
                min_len = min(min_len, i - prefix_mod_map[needed_mod]);
            }
            
            prefix_mod_map[current_mod] = i;
        }
        
        return min_len == nums.size() ? -1 : min_len; 
    }
};


class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        
    }
};