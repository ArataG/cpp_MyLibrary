/**
  file   :  WashallFloyd.cpp
  brief  : 全点対間の最短経路問題に利用する．O[|v|^3] v:　頂点数
  author : S.SUGIHARA
  date   : 2020-08-23
  update :
 */

/**
  参考資料： RASEN本(アルゴリズムとデータ構造)
  コードテスト(AOJ)：https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
*/

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;

//
static const int MAX = 100;
static const long long INFTY = (1LL<<32);

int n;
long long d[MAX][MAX];  //d[i][j]の最短コストを記録するDPテーブル

void floyd() {

  for( int k = 0; k < n; k++){         //経由する頂点数
    for(int i = 0; i < n; i++){         //始点
      if( d[i][k] == INFTY ) continue;

      for(int j = 0; j < n; j++){       //終点
      if( d[k][j] == INFTY ) continue;
      d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      //i -> j   i -> k -> j //iからｊへの最短経路を示す

      }
    }
  }
}


int main() {
  int e, u, v, c; //e: 辺の数, 頂点 u --> 頂点 v のコスト ｃ
  cin >> n >> e;

  //隣接行列リストの初期化 始点 --> 始点 を 0 に，　それ以外を　INFTY
  for( int i = 0; i < n; i++){
    for( int j = 0; j < n; j++){
      if(i == j) d[i][j] = 0;
      else d[i][j] = INFTY;
      //d[i][j] = ((i == j) ? 0 : INFTY);
    }
  }

  //隣接行列リストとして入力
  for(int i = 0; i < e; i++){
    cin >> u >> v >> c;
    d[u][v] = c;

    //無向グラフならば
    //d[v][u] = c;を追加
    //多重辺がある場合には，
    //d[[u][v] = min(d[u][v],c)
  }

  //Washall-Floydによる最短路の検索

  floyd();

  //グラフに負の Closed Loopがないかの確認
  bool negative = false;
  for( int i = 0; i < n; i++ ){
    if( d[i][i] < 0) negative = true;
  }

  //Output
  if( negative ){
    cout << "NEGATIVE CYCLE" << endl;
  }
  else{
    for( int i = 0; i < n; i++){
      for( int j = 0; j < n; j++){
        if( j ) cout << " ";
        if( d[i][j] == INFTY ) cout << "INF";
        else cout << d[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
