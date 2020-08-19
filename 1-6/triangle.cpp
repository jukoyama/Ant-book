# include <bits/stdc++.h>
using namespace std;

int solve(vector<int> a) {
  int n = a.size();
  int ans = 0;
  for (int i=0; i<n; i++) {
    for (int j=i+1; j<n; j++) {
      for (int k=j+1; k<n; k++) {
	int len = a.at(i) + a.at(j) + a.at(k);
	int max_len = max({a.at(i), a.at(j), a.at(k)});
	int rest_len = len - max_len;
	if ( max_len < rest_len ) {
	  ans = max (ans, len);
	}
      }
    }
  }
  return ans;
}

int main() {
  int n1 = 5;
  int n2 = 4;
  vector<int> a1 = {2, 3, 4, 5, 10};
  vector<int> a2 = {4, 5, 10, 20};

  int ans = solve(a2);

  cout << ans << "\n";
  
}
