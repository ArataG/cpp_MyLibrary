/**
File   :  UnionFind-getlist.cpp
Brief  :  UnionFindを使うことができる．宣言，uniteで連結，sameで同じ連結成分に属しているか，sizeで連結成分の大きさを返す．連結成分のリストの取得も追加した
*/

/**
Reference： atcoder　live_library
Code test： https://atcoder.jp/contests/arc106/tasks/arc106_b
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
  int find(x); 各連結成分の代表を返す
  bool unite(x,y); 要素xと要素yを連結する
  int size(x);　要素xの所属する連結成分のサイズを返す．
  bool same(x,y);  連結しているかを返す
  getList(uflist,n) 連結成分の
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
//連結成分リストを返す(#TODO:nullも返している．改善の余地有り)
void getList(vector<vector<int>>& conectList,int n){
  for(int i = 0; i < n; i++) conectList[find(i)].push_back(i);
}
};



int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> b(n);

  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];

  //
  UnionFind uF(n);
  REP(i,m){
    int c, d;
    cin >> c >> d;
    --c; --d;
    uF.unite(c, d);
  }

  vector<vector<int>> ufList(n); 
  uF.getList(ufList,n);

  REP(i, n){
    if(ufList[i].empty()) continue; //listが空なら飛ばす
    ll asum = 0;
    ll bsum = 0;
    REP(j, ufList[i].size()) { //連結成分ごとに表示
      //cout << ufList[i][j] << " ";
      asum += (ll)a[ufList[i][j]];
      bsum += (ll)b[ufList[i][j]];
    }
    if(asum != bsum ) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;


  // 連結成分ごとのリストを取得する方法
  /*
  vector<vector<int>> ufList(n); 
  uF.getList(ufList,n);

  REP(i, n){
    if(ufList[i].empty()) continue; //listが空なら飛ばす
    REP(j, ufList[i].size()) { //連結成分ごとに表示
      cout << ufList[i][j] << " ";
    }
    cout << endl;
  }
  */
}