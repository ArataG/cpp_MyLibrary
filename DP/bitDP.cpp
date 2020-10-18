//調整中

/**
File   :  bitDP.cpp
Brief  :  TSP(巡回セールスマン)問題のbitDPを利用した解法
*/

/**
Reference： https://qiita.com/drken/items/a14e9af0ca2d857dad23
Code test： https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/2/DPL_2_A
整数nを入力すると，その約数を昇順に出力する．
*/

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;


int n, m;
int dist[21][21];

//dpテーブル
int dp[(1<<20) + 1][21];

int rec(int bit, int v){

  //探索済みならリターン
  if(dp[bit][v] != -1) return dp[bit][v];
  
  //初期値
  if(bit == (1<<v) ){
    return dp[bit][v] = 0;
  }

  int res = INF;

  //bitの頂点vを除いたもの
  int prev_bit = bit & ~(1<<v);

  //vの手前のノードとして，uを全探索
  REP(u, n){
    if (!(prev_bit & (1<<u))) continue; // u が prev_bit になかったらスキップ
    
    //探索
    res = min(res, rec(prev_bit, u) + dist[u][v]);
    // if (res > rec(prev_bit, u) + dist[u][v]) {
    // res = rec(prev_bit, u) + dist[u][v];
    // }
  }


  return dp[bit][v] = res;  
}


int main(){
  cin >> n >> m; //n:頂点数，m:辺の数

  //各辺の値をINF(到達できないに初期化) 座標が与えられている場合は，普通に計算したコストを入力すれば良い．
  REP(i,n)REP(j,n) dist[i][j] = INF;
  //各辺のコストと入力
  int s, t, d;
  REP(i,m){
    cin >> s >> t >> d;
    dist[s][t] = d;
  }

  // REP(i,n){REP(j,n){
  //   if(dist[i][j] == INF) cout << -1 << " ";
  //   else cout << dist[i][j] << " ";
  // }
  //  cout << endl;
  // }

  //dpテーブルを未訪問(-1)に初期化する
  REP(bit, 1<<n + 1){
    REP(j, n) dp[bit][j] = -1;
  }

  //探索
  int ans = INF;
  ans = rec((1<<n)-1, 0);


  if(ans == INF) cout << -1 << endl;
  else cout << ans << endl;

  return 0;

}