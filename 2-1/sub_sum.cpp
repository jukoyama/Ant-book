#include <bits/stdc++.h>
using namespace std;

bool solve (vector<int> a, int k, int i, int sum) {
  int n = a.size();
  
  // n個までたどり着いた
  if ( i==n ) return sum == k;

  // n番目を使わない場合
  else if ( solve(a, k, i+1, sum) ) return true;

  // n番目を使う場合
  else if ( solve(a, k, i+1, sum+a.at(i)) ) return true;

  else return false;
}

int main() {
  int n = 4;
  vector<int> a = {1, 2, 4, 7};
  int k = 15;

  bool b = solve(a, k, 0, 0);
  if (b) cout << "Yes\n";
  else cout << "No\n";
}
