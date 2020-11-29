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
//debug 
#ifdef _DEBUG
#define debug(var)  do{cout << #var << " :";view(var);}while(0)
#else
#define debug(...)
#endif
template<typename T> void view(T e){cout << e << endl;}
template<typename T> void view(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}
template<typename T> void view(const vector<vector<T> >& vv){ for(const auto& v : vv){ view(v); } }

vector<int> edge[100005];
//メモ化再帰
int memo[100005];
bool seen[100005];  //falseに初期化

int dp(int v){
  if(seen[v]) return memo[v];//
  int ans = 0;
  for(auto x: edge[v]){
    ans = max(ans, dp(x)+1);
  }
  memo[v] = ans;//
  seen[v] = true;//
  return ans;
}

int main(){
  //#define int long long
  int n, m;
  cin >> n >> m;
  REP(i,m){
    int u, v;
    cin >> u >> v;
    edge[u].push_back(v);
  }

  int ans = 0;
  REP2(v, 1, n+1){
    ans = max(ans, dp(v));
  }

  cout << ans << endl;
  return 0;
}
/*

dp[x] = xから始まる最長経路
dp[x] = max(dp[y] + 1)
xから直接辺が伸びている頂点yすべてのmaxを取る

DPを埋める順番を, トポロジカルソートで求める.
DAGをみたら >> DP
//以下の時はメモ化再帰が楽
1. 漸化式だけ立っている.
2. 良い順番がわかる(DAGが見えたら, メモ化再帰がかける.閉路がないと嬉しい? )
3. その順番はわからない.

for文ではなく, メモ化再帰.

*/