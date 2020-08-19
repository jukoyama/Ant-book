#include <bits/stdc++.h>
using namespace std;

pair<int, int> solve(vector<int> x, int L) {
  int n = x.size();
  int min_t = 0;
  int max_t = 0;

  for (int i=0; i<n; i++) {
    int a = x.at(i);
    int l1 = min (a, L-a);
    int l2 = max (a, L-a);
    min_t = max (min_t, l1);
    max_t = max (max_t, l2);
  }

  return make_pair(min_t, max_t);
}

int main() {
  int L = 10;
  int n = 3;
  vector<int> x = {2, 6, 7};

  pair<int, int> ans = solve(x, L);

  cout << "min = " << ans.first  << "\n";
  cout << "max = " << ans.second << "\n";
}
