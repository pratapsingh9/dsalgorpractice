#include <iostream>
#include <vector>
using namespace std;

class Queu {
  vector<int> arr;
  int front, rear, size;

 public:
  Queue(int capacity) : size(capacity), front(0), rear(0) { arr.resize(size); }

  void push(int x) {
    if (rear == size) {
      cout << "Queue overflow error";
      return;
    }

    arr[rear++] = x;
  }

  int pop() {
    if (isempty()) {
      cout << "stack is empyt" << endl;
      return -1;
    }
    return arr[front++];
  }
  int peek() {
    if (isempty()) {
    }
    return arr[front];
  }

  bool isempty() { return front == rear; }
}

vector<int>
calculateNSLeft(const vector<int>& heights) {
  int n = heights.size();
  vector<int> nsLeft(n);
  stack<int> s;

  for (int i = 0; i < n; i++) {
    while (!s.empty() && heights[s.top()] >= heights[i]) {
      s.pop();
    }
    nsLeft[i] = s.empty() ? -1 : s.top();  // -1 if no smaller element
    s.push(i);
  }
  return nsLeft;
}

// Function to calculate Nearest Smaller to Right
vector<int> calculateNSRight(const vector<int>& heights) {
  int n = heights.size();
  vector<int> nsRight(n);
  stack<int> s;

  for (int i = n - 1; i >= 0; i--) {
    while (!s.empty() && heights[s.top()] >= heights[i]) {
      s.pop();
    }
    nsRight[i] = s.empty() ? n : s.top();  // n if no smaller element
    s.push(i);
  }
  return nsRight;
}

// Function to calculate the maximum rectangular area in a histogram
int maxHistogramArea(const vector<int>& heights) {
  vector<int> nsLeft = calculateNSLeft(heights);    // Calculate NSLeft
  vector<int> nsRight = calculateNSRight(heights);  // Calculate NSRight
  int maxArea = 0;
  for (int i = 0; i < heights.size(); i++) {
    int h = nsRight - nsLeft - 1;
    int area = h * heights[i];
    maxArea = max(maxArea, area);
  }
  return maxArea;
}

int maxHistorgarmColection(vector<int> hie) {
  stack<int> s;
  int maxarea = 0;
  int n = hie.size();

  for (int i = 0; i <= n; ++i) {
    /* code */
    int currHieght = (i == n) ? 0 : hie[i];
    while (!s.empty() && heights[s.top()] > currHieght) {
      int h = heights[s.top()];
      s.pop();
    }
  }
}

class Minstack {
 private:
  stack<int> st, minst;

 public:
  void push(int x) {
    st.push(x);
    if (minst.empty() || minst.top() > x) {
      minst.push(x);
    }
  }
  void pop() {
    if (st.top() == minst.top()) {
      minst.pop();
    }
    st.pop();
  }
  int top() { return st.top(); }

  int getMin() { return minst.top(); }
}