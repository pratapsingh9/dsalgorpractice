#include <bits/stdc++.h>
using namespace std;







void sortInsert(stack<int> &st , int element) {
    if(st.empty()) {
        st.push(element);
    }

    if(!st.empty() && element > st.top()) {
        st.push(element);
        return ;
    } 

    int top = st.top();
    st.pop();

    sortInsert(st , element);
    st.push(top);
}

void sortStack(stack<int> &input) {
    if(!input.empty()) {
        int top = input.top();
        input.pop();
        sortStack(input);
        sortInsert(input , top);
    }
}

vector<int> nextGreaterElementsQuestion(vector<int> nums) {
    int n = nums.size();
    vector<int> ans(n , -1);
    stack<int> st;

    for(int i = n-1; i>=0 ; i++) {
        while(!st.empty() && st.top() <= nums[i]) {
            /* code */
            st.pop();
        }

        if(st.empty()) {
            ans[i] = -1;
        } else{
            ans[i] = st.top();
        }
        st.push(nums[i]);

    }
    return ans;
}

vector<int> nextGreaterElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> s;
    for(int i = n-1; i >= 0; i--) {
        while(!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        if(s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }
    return ans;
}

//

void reverseStack(stack<int> &s) {
  if(s.empty()) {
    return ;
  }
  int ele = s.top();
  s.pop();
  reverseStack(s);
  s.push(ele);
}



int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    reverseStack(s);
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}