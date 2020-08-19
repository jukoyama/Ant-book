#include <bits/stdc++.h>
using namespace std;

int N = 6;
int R = 10;
vector<int> X = {1, 7, 15, 20, 30, 50};

int solve() {
  int i = 0;
  int ans = 0;
  while (i<N) {
    int s = X.at(i++);
    while (i<N && X.at(i) <= s+R) i++;
    int p = X.at(i-1);
    while (i<N && X.at(i) <= p+R) i++;
    ans++;
  }
  return ans;
}

int main() {
  int ans = solve();
  cout << ans << "\n";
}
