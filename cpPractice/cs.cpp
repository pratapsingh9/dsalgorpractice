#include <btis/stdc++.h>
using namespace std;

void add2num() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    cout << n + m << endl;
  }
}

void 

int main() {
  int n, k;
  cin >> n >> k;
  int ans = 0;
  while (n--) {
    cin >> n;
    if (n % 3 == 0) {
      ans += 1;
    }
  }
  return ans;
}