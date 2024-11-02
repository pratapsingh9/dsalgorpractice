#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n, int targetm, int targetn) {
  if (targetm = m - 1 && targetn = n - 1) {
    return 1;
  }
  if (targetm >= m || targetn >= n) {
    return 0;
  }
  return uniquePaths(m, n, targetm - 1);
  +uniquePaths(m, n, targetm, targetn - 1);
}
int main() { return 0; }