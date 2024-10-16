#include <bits/stdc++.h>
using namespace std;

int main() {
  unordered_map<char, char> brackets = {{')', '('}, {'}', '{'}, {']', '['}};
  cout << brackets.count('(') << endl;
  return 0;
}