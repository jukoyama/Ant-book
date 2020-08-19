#include <bits/stdc++.h>
using namespace std;

vector<int> V = {1, 5, 10, 50, 100, 500};
vector<int> C = {3, 2, 1, 3, 0, 2};
int A = 620;

int solve() {
  int ans = 0;
  int n = 5;
  for (int i=n; i>=0; i--) {
    int x = min (A/V.at(i), C.at(i));
    A -= x * V.at(i);
    ans += x;
  }
  return ans;
}

int main() {
  int ans = solve();
  cout << ans << "\n";
}
