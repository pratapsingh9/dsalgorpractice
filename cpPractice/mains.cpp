#include <bits/stdc++.h>
using namespace std;

int select() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s = to_string(n);
    long long int sum = 0;
    for (int i = 0; i < s.length(); i++) {
      char ch = s[i];
      int p = (int)ch;
      p -= 48;
      sum += p;
    }
    cout << sum << endl;
  }
}



int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    ostringstream strs;
    strs << n;
    string s = strs.str();

    long long int sum = 0;
    for (int i = 0; i < s.length(); i++) {
      char ch = s[i];
      int p = (int)ch;
      p -= 48;
      sum += p;
    }
    cout << sum << endl;
  }
}
