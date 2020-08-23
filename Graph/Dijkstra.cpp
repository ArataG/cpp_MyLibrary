/**
  file   :  Dijkstra.cpp 
  brief  :  単一始点最短経路問題．重み付きグラフ.負のコストがある場合は使えない．O[|V|^2]
  author :  S.SUGIHARA
  date   :  2020-08-23
  update :
 */

/**
  参考資料： RASEN本(アルゴリズムとデータ構造)
  コードテスト(AOJ)： 
*/

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

static const int MAX = 10000;
static const int INFTY  = (1 << 20);

static const int WHITE = 0;
static const int GRAY  = 1;
static const int BLACK = 2;



int n;
vector<pair<int, int>> adj[MAX];
//グラフの隣接リスト表現(重み付き有向)　first:隣接頂点，second; コスト

void dijkstra(){
  priority_queue<pair<int, int>> PQ;  //各隣接頂点の始点からのコストのキュー
  int color[MAX]; //訪問状況
  int d[MAX];     //始点から各頂点までの最小コスト
  //初期化
  for(int i = 0; i < n; ++i){
    d[i] = INFTY;
    color[i]  = WHITE;
  }

  //始点のコストｄ[0]と，，priority_quwueに代入
  d[0] = 0;
  PQ.push(make_pair(0, 0));
  color[0] = GRAY;


  //最短経路の探索ループ

  while( !PQ.empty() ){
     //最小コストの頂点を取得し，確定
    pair<int, int> f = PQ.top(); PQ.pop();
    int u = f.second;
    color[u] = BLACK;

    //最小値を取り出し，それが最短でなければ無視
    if( d[u] < f.first*(-1) ) continue;

    for(int j = 0; j < adj[u].size(); ++j){
      int v = adj[u][j].first;
      if( color[v] == BLACK ) continue; //確定した頂点は飛ばす

      //最小コストを比較して，　更新
      if( d[v] > d[u] + adj[u][j].second ){
        d[v] = d[u] + adj[u][j].second;
        PQ.push(make_pair(d[v]* (-1), v));
        //priority_queueは大きい値を優先するため，−１をかける．
        color[v] = GRAY;
      }
    }
  }

  for( int i = 0; i < n; i++ ){
    cout << i << " "  << (d[i] == INFTY ? -1 : d[i]) << endl;
  }


}

int main(){
  //Input
  int k, u, v, c; //頂点uに隣接する頂点の数， 頂点, 頂点ｋに隣接する頂点, u>vのコスト
  cin >> n;

  REP(i,n){
    cin >> u >> k;
    REP(j,k){
      cin >> v >> c;
      adj[u].push_back(make_pair(v, c));
    }
  }

  //
  dijkstra();

  return 0;
}
