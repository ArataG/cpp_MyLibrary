/**
File   :  UnionFind.cpp
Brief  :  UnionFindを使うことができる．宣言，uniteで連結，sameで同じ連結成分に属しているか，sizeで連結成分の大きさを返す．
Author :  S.SUGIHARA
Date   :  2020-08-30
Update :
*/

/**
Reference： atcoder　live_library
Code test： https://atcoder.jp/contests/abc157/tasks/abc157_d
177d もUnionFind
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


/*
  UnionFind
*/
struct UnionFind {
vector<int> d;
UnionFind(int n = 0): d(n,-1) {}
int find(int x) {
  if (d[x] < 0) return x;
  return d[x] = find(d[x]);   //経路縮尺(メモ化再帰)
}
bool unite(int x, int y) {  //連結する
  x = find(x); y = find(y);
  if (x == y) return false;
  if (d[x] > d[y]) swap(x,y); //根の高さが小さい方に連結する
  d[x] += d[y];
  d[y] = x;
  return true;
}
bool same(int x, int y) { return find(x) == find(y);} //連結しているかを返す
int size(int x) { return -d[find(x)];}  //連結成分サイズを返す
};

int deg[100005];//直接接続している友人数のリスト
vector<int> to[100005]; //ブロック関係の連結リスト

int main(){
  int n, m, k;
  cin >> n >> m >> k;
  UnionFind uF(n);
  REP(i,m){
    int a, b;
    cin >> a >> b;
    --a; --b;
    deg[a]++;
    deg[b]++;
    uF.unite(a,b);
  }

  REP(i,k){
    int a, b;
    cin >> a >> b;
    --a; --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  REP(i,n){
    //連結成分のサイズ　- 自分　- 直属の友人
    int ans = uF.size(i) - 1 -deg[i];

    //連結成分内のブロック関係ならマイナス
    for(int u: to[i]){
      if(uF.same(i,u)) --ans;
    }
    cout << ans << " ";
  }
  return 0;
}
