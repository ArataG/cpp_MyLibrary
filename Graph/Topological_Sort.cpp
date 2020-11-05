/**
  file   :  topological_sort.cpp 
  brief  : 有向非巡回グラフ(DAG)の各ノードを順序付けする．どのノードも，その出力変の先のノードより前に来るように並べ替える．
  BFSでトポロジカルソートを行う O([V]+[E])
 */

/**
  参考資料： RASEN本(アルゴリズムとデータ構造)
  コードテスト(AOJ)： https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B
  応用問題：　https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_d
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
static const int MAX = 100000;

vector<int> G[MAX];
list<int> out;
bool V[MAX]; //頂点が探索したかを記録
int N;
int indeg[MAX];//各頂点に入力される辺の数

void bfs(int s){
  queue<int> q;
  q.push(s);
  V[s] = true; //頂点を探索済みに
  while(!q.empty()){
    int u = q.front(); q.pop();
    out.push_back(u); // 答えに追加
    for(int i = 0; i < G[u].size(); i++){
      int v = G[u][i];
      indeg[v]--; //チェックした辺をへらす
      if(indeg[v] == 0&& !V[v]){
        V[v] = true;
        q.push(v);
      }
    }
  }
}
void tsort(){

  for(int i = 0; i < N; i++){
    indeg[i] = 0;
  }

  for(int u = 0; u < N; u++){
    for(int i = 0; i < G[u].size(); i++){
      int v = G[u][i];
      indeg[v]++;
    }
  }

  for(int u = 0; u < N; u++){
     //どこからも辺が入力されていない&未探索の頂点からbfs開始
     if(indeg[u] == 0 && !V[u]) bfs(u);
  }
  
  //
  for( list<int>::iterator it = out.begin(); it != out.end(); it++){
    cout << *it  << endl;
  }
}

int main(){
  int s, t, M;
  cin >> N >> M; //頂点数，変の数


  //頂点を非探索に初期化  
  for(int i = 0; i < N; i++) V[i] = false;

  //input 隣接行列リストにinput
  for(int i = 0; i < M; i++ ){
    cin >> s >> t;
    G[s].push_back(t);
  }

  //Topological sort start
  tsort();

  return 0;
}