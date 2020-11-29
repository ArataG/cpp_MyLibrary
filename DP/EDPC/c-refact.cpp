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

const int NMAX=10e5+5;
const int M = 3; //状態数
int dp[NMAX][M];

int main(){
  int n;
  cin >> n;
  //状態を二次元配列に持っておくと, もっとシンプルにかける.
  vector<vector<int>> A(n, vector<int>(M, 0)); 
  REP(i,n) REP(j,M) cin >> A[i][j];
  REP(j,M) dp[0][j] = A[0][j]; 

  REP(i,n){
    if(i == 0) continue;
    REP(j,M){
      REP(k,3) if(j!=k) dp[i][j] = max(dp[i][j], dp[i-1][k] + A[i][j]);
    }
  }
  int ans = max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
  cout << ans << endl;
  return 0;
}