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

//漸化式がかける
/*
dp[i][0] //a
dp[i][1] //b
dp[i][2] //c
前日に行った活動はできない.

dp[i][0] = max(dp[i-1][1] + a[i], dp[i-1][2]+a[i]);
これをa-cの三通り書く
*/

const int NMAX=10e5+5;
const int M = 3; //状態数
int dp[NMAX][M];
int main(){
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  REP(i,n) cin >> a[i] >> b[i] >> c[i];
  dp[0][0] = a[0];
  dp[0][1] = b[0];
  dp[0][2] = c[0]; 

  REP(i,n){
    if(i == 0) continue;
    dp[i][0] = max(dp[i-1][1] + a[i], dp[i-1][2] + a[i]);
    dp[i][1] = max(dp[i-1][0] + b[i], dp[i-1][2] + b[i]);
    dp[i][2] = max(dp[i-1][0] + c[i], dp[i-1][1] + c[i]);
  }
  int ans = max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
  cout << ans << endl;
  return 0;
}