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

// knapsack
// 品物が1個ずつしか無いタイプ

const int NMAX = 105;
const int WMAX = 10e5+5;
ll dp[NMAX][WMAX];

int main(){
  //#define int long long
  int N, W;
  cin >> N >> W;
  vector<int> w(N+1); 
  vector<int> v(N+1);
  REP2(i,1,N+1) cin >> w[i] >> v[i];
  REP2(i, 1, N+1){
    REP2(j, 1, W+1){
      if(j - w[i] >= 0) dp[i][j] = max(dp[i-1][j], dp[i-1][j - w[i]]+ v[i]);
      else dp[i][j] = dp[i-1][j]; 
    }
  }
  //output
  cout << dp[N][W] << endl;
  //REP(j, N+1) REP(i,W+1) {cout << dp[j][i] << " "; if(i == W) cout << endl;}
  return 0;
}