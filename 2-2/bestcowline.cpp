#include <bits/stdc++.h>
using namespace std;

int    N = 6;
string S = "ACDBCB";

string solve() {
  int a = 0;
  int b = N-1;
  string ans = "";
  while (a<=b) {
    bool left = false;
    for (int i=0; a+i<=b; i++) {
      if (S.at(a+i) < S.at(b-i)) {
	left = true;
	break;
      } else if (S.at(a+i) > S.at(b-i)) {
	break;
      }
    }
    if (left) {
      ans += S.at(a); a++;
    } else {
      ans += S.at(b); b--;
    }
  }
  return ans;
}

int main() {
  string ans = solve();
  cout << ans << "\n";
}
