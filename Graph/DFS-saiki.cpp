/**
  file   :  DFS-saiki.cpp 
  brief  :  再帰関数による深さ優先探索, 入力形式: 隣接行列
  出力
  頂点の番号 その頂点の発見時刻 その頂点の完了時刻
 */

/**
  参考資料：RASEN本(アルゴリズムとデータ構造)
  コードテスト(AOJ)： https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_B
*/

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);


//---------------------------//
//DFS 再帰関数を利用
//隣接行列による実装
//各頂点についてすべての頂点について隣接しているか調べているため
// 計算量はO[N^2]
// 大きなグラフに対しては不向き ==> 隣接リストによる実装を行う
//隣接リストによる実装方法は　DFS２
//

static const int N     = 100;
static const int WHITE = 0;
static const int GRAY  = 1;
static const int BLACK = 2;

//隣接行列
int n, M[N][N];
int color[N], d[N], f[N], tt;

void dfs_visit(int u){
  //cout << "u: " << u << endl; //来訪地点のチェック
  color[u] = GRAY;
  d[u] = ++tt;  //最初に訪れたときの処理
  REP(v,n){
    if(M[u][v] == 0) continue;
    //cout << "v: " << v << endl; // 次に向かう点をチェック
    if(color[v] == WHITE) {
      dfs_visit(v); //再帰
    }
  }
  color[u] = BLACK;
  f[u] = ++tt;  //最後に訪れたときの処理
}

void dfs(){
  // 初期化
  REP(u,n) color[u] = WHITE;
  tt = 0;
  //dfs start
  REP(u,n) {
    if( color[u] == WHITE) dfs_visit(u); //再帰関数に移動
  }
  REP(u,n){
    cout << u+1 << " " << d[u] << " " << f[u] << endl;
  }
}

int main(){
  int u, k, v;
  cin >> n;
  //隣接行列の初期化
  REP(i,n) REP(j,n) M[i][j] = 0;

  //隣接行列の作製
  REP(i,n){
    cin >> u >> k;
    --u;
    REP(j,k){
      cin >> v;
      --v;
      M[u][v] = 1;
    }
  }

  //dfs
  dfs();
  
  return 0;
}
