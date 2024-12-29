#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, k;
  cin >> t >> k;

  while (t--) {
    vector<string> res;

    for (int i = 0; i < k; i++) {
      string w;
      cin >> w;

      int v = 0;
      for (char c : w) {
        if (isalpha(c)) {
          v += tolower(c) - 'a' + 1;
        }
      }

      char s = (v % 2 == 0) ? '@' : '#';
      res.push_back(string(1, s) + to_string(v % 26));
    }

    for (const auto &x : res) {
      cout << x << " ";
    }

    cout << endl;
  }
  return 0;
}
