#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
/**
  file   :  Kruskal.cpp (use Union Find Library)
  brief  :  最小全域木の辺の重みの総和を計算する．O[|E|log|E|]
  author :  S.SUGIHARA
  date   :  2020-08-23
  update :
 */

/**
  参考資料： RASEN本(アルゴリズムとデータ構造)
  コードテスト(AOJ)： https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
*/
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;

//
class DisjointSet{
  public:
    vector<int> rank, p;  //rank:根の高さ， ｐ:代表
    DisjointSet(int size){
      rank.resize(size, 0);
      p.resize(size, 0);
      for(int i = 0; i < size; i++) makeSet(i);
    }

    void makeSet(int x){
      p[x] = x;
      rank[x] = 0;
    }

    bool same(int x, int y){
      return findSet(x) == findSet(y);
    }

    void unite(int x, int y){
      link(findSet(x), findSet(y));
    }

    void link(int x, int y){
      if( rank[x] > rank [y]){
        p[y] = x;
      }
      else{
        p[x] = y;
        if(rank[x] == rank[y]){
          rank[y]++;
        }
      }
    }

    int findSet(int x){
      if( x != p[x]){
        p[x] = findSet(p[x]);
      }
      return p[x];
    }
};

class Edge {
  public:
  int source, target, cost;
  Edge(int source = 0, int target = 0, int cost = 0):
  source(source), target(target), cost(cost){}
  bool operator < ( const Edge & e) const{
    return cost < e.cost;
  }
};

int kruskal(int N, vector<Edge> edges){

  //vector<Edge> MST; 最小全域木を復元したいときは宣言して使う
  int totalCost = 0;
  //辺を昇順にソート
  sort(edges.begin(), edges.end());

  DisjointSet dset = DisjointSet(N + 1);

  //DS初期化
  for(int i = 0; i < N; i++) dset.makeSet(i);

  int source, target;
  for(int i = 0; i < edges.size(); i++){
    Edge e = edges[i];
    if( !dset.same(e.source, e.target)) {
      //MST.push_back(e);
      totalCost += e.cost;
      dset.unite( e.source, e.target);
    }
  }
  return totalCost;
}

int main(){
  int N, M, cost;
  int source, target;

  cin >> N >> M;
  vector<Edge> edges;

  REP(i,M){
    cin >> source >> target >> cost;
    edges.push_back(Edge(source, target, cost));
  }

  cout << kruskal( N, edges ) << endl;

  return 0;
}
