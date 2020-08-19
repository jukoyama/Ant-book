#include <bits/stdc++.h>

using namespace std;

bool f (vector<int> k, int n, int m) {
  for (int a=0; a<n; a++) {
    for (int b=0; b<n; b++) {
      for (int c=0; c<n; c++) {
	for (int d=0; d<n; d++) {
	  if ( k.at(a)+k.at(b)+k.at(c)+k.at(d) == m ) {
	    return true;
	  }
	}
      }
    }
  }
  return false;
}

bool g (vector<int> k, int n, int m) {
  for (int a=0; a<n; a++) {
    for (int b=0; b<n; b++) {
      for (int c=0; c<n; c++) {
	int r = m - k.at(a) - k.at(b) - k.at(c);
	bool bl = binary_search(k.begin(), k.end(), r);
	return bl;
      }
    }
  }
  return false;
}

bool h (vector<int> k, int n, int m) {
  vector<int> l(n*n);
  for (int c=0; c<n; c++) {
    for (int d=0; d<n; d++) {
      l.at(n*c+d) = k.at(c) + k.at(d);
    }
  }
  sort(l.begin(), l.end());
  for (int a=0; a<n; a++) {
    for (int b=0; b<n; b++) {
      int r = m - k.at(a) - k.at(b);
      bool bl = binary_search(l.begin(), l.end(), r);
      return bl;
    }
  }
  return false;
}

int main() {
  int n = 3;
  int m = 10;
  vector<int> k = {1, 3, 5};

  // k[a] + k[b] + k[c] + k[d] = m
  // O(n^4)
  bool b1 = f (k, n, m);

  sort(k.begin(), k.end());
  
  // k[d] = m - k[a] - k[b] - k[c]
  // O(n^3 * log n)
  bool b2 = g (k, n, m);
  
  // k[c] + k[d] = m - k[a] - k[b]
  bool b3 = h (k, n, m);

  if (b3) cout << "Yes\n";
  else cout << "No\n";
}
