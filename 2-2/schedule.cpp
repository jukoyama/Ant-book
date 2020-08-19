#include <bits/stdc++.h>
using namespace std;

int n = 5;
vector<int> s = {1, 2, 4, 6, 8};
vector<int> t = {3, 5, 7, 9, 10};
vector<pair<int, int>> p(n);

int solve() {
  int ans = 0;
  int time = 0;
  for (int i=0; i<n; i++) {
    if (time < p.at(i).second) {
      time = p.at(i).first;
      ans ++;
    }
  }
  return ans;
}

int main() {

  for (int i=0; i<n; i++) {
    p.at(i).first = t.at(i);
    p.at(i).second = s.at(i);
  }
  sort(p.begin(), p.end());
  
  int ans = solve();
  cout << ans << "\n";
}
