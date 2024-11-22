#include <bits/stdc++.h>
using namespace std;

bool canMakeEqual(string s, string t) {
  if (s.length() != t.length()) {
    return false;
  }

  int sCount = 0, tCount = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'a') {
      sCount++;
    }
    if (t[i] == 'a') {
      tCount++;
    }
  }

  if (sCount != tCount) {
    return false;
  }

  int i = 0, j = 0;
  while (i < s.length() && j < t.length()) {
    while (i + 1 < s.length() && (s[i] != 'a' || s[i + 1] != 'a')) {
      i++;
    }

    while (j + 1 < t.length() && (t[j] != 'a' || t[j + 1] != 'a')) {
      j++;
    }

    if (i == s.length() && j == t.length()) {
      return true;
    }

    if (i == s.length() || j == t.length()) {
      return false;
    }

    if (i < j) {
      s = s.substr(0, i) + "abab" + s.substr(i + 2);
    } else {
      t = t.substr(0, j) + "abab" + t.substr(j + 2);
    }
  }

  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    if (canMakeEqual(s, t)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}