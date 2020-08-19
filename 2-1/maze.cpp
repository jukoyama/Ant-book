#include <bits/stdc++.h>
using namespace std;

int n = 10;
int m = 10;
int sx = 1;
int sy = 0;
int gx = 8;
int gy = 9;

typedef pair<int, int> P;
typedef pair<int, bool> D;

// 通った道は、true にする
vector<vector<pair<int, bool>>> d(n, vector<pair<int, bool>>(m, D(0, true)));

vector<vector<int>> l =
  {{'#','S','#','#','#','#','#','#','.','#'},
   {'.','.','.','.','.','.','#','.','.','#'},
   {'.','#','.','#','#','.','#','#','.','#'},
   {'.','#','.','.','.','.','.','.','.','.'},
   {'#','#','.','#','#','.','#','#','#','#'},
   {'.','.','.','.','#','.','.','.','.','#'},
   {'.','#','#','#','#','#','#','#','.','#'},
   {'.','.','.','.','#','.','.','.','.','.'},
   {'.','#','#','#','#','.','#','#','#','.'},
   {'.','.','.','.','#','.','.','.','G','#'}};

// 右 左 下 上
vector<pair<int, int>> mv = {P(1, 0), P(-1, 0), P(0, 1), P(-1, 0)};

void f (queue<P> q) {
  queue<P> r = q;
  while (r.size()) {
    cout << "(" << r.front().first << ", " << r.front().second << ")";
    r.pop();
  }
  cout << "\n";
}

int bfs() {
  queue<P> que;
  
  // queに初期値を入れる
  que.push(P(sx, sy));

  // スタート地点を false
  d.at(sy).at(sx).second = false;

  // queが空になるまでループする
  while ( que.size() ) {
    // que の先頭要素を取り出す
    P p = que.front(); que.pop();
    
    // 先頭要素がゴールならば、探索を終了
    if ( p.first == gx && p.second == gy ) break;
    
    // p から１ステップで移動できる座標を探す
    for (int i=0; i<4; i++) {
      // 一歩移動
      int nx = p.first + mv.at(i).first;
      int ny = p.second + mv.at(i).second;
      // その場所が移動できるか確認 
      if (0 <= nx && nx < n && 0 <= ny && ny < m
	  && l.at(ny).at(nx) != '#' && d.at(nx).at(ny).second ) {
	// 移動可能 かつ 通ったことのない場所なら、queに座標を入れる
	que.push(P (nx, ny));
	d.at(nx).at(ny).first = d.at(p.first).at(p.second).first + 1;
	d.at(nx).at(ny).second = false;
      }
    }
    f(que);
  }
  return d.at(gx).at(gy).first;
}

int main(){
  cout << bfs() << "\n";
}
