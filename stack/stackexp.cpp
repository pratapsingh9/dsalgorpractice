#include <bits/stdc++.h>
using namespace std;



bool isValid(string input) {
    stack<char> s;
    for (char word : input) {
        if (word == '(' || word == '{' || word == '[') {
            s.push(word);
        } else {
            if (s.empty()) return false;
            char top = s.top();
            s.pop();
            if ((word == ')' && top != '(') || 
                (word == '}' && top != '{') || 
                (word == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.empty();
}


void insertAtend(stack<char> &s , char ch) { 
    if(s.empty()) {
        s.push(ch);
        return ;
    }
    char tops = s.top();
    s.pop();
    insertAtend(s , ch);
}

void seprateBlackAndwhtie(string &s) {
    stack<char> st;  
    for(char ch : s) {
        if(ch == '0') { 
            st.push(ch);
        }
        else {
            insertAtend(st , ch); 
        }
    }
    while(!st.empty()) {
    	char ans = st.top();
    	cout <<  ans << endl;
    	st.pop();
    }
}

int main() {
    string s = "01001101";
    seprateBlackAndwhtie(s);

    return 0;
}
