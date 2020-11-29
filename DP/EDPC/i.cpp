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

const int NMAX = 3005;
double dp[NMAX][NMAX];

int main(){
  //#define int long long
  int n;
  cin >> n;
  vector<double> p(n);
  REP(i,n) cin >> p[i];

  dp[0][0] = 1;
  REP2(i,1,n+1){
    REP2(j,0,i+1){
      if(j == 0) dp[i][j] = dp[i-1][j] * (1-p[i-1]);
      else dp[i][j] = dp[i-1][j-1] * p[i-1] + dp[i-1][j] * (1-p[i-1]);
    }
 }
 
  double ans = 0;
  REP(i, n+1){
    if(i >= (n+1)/2) ans += dp[n][i];
  }
  cout << fixed << setprecision(10) << ans << endl;
  
//   REP(i,n+1){
//    REP(j,n+1) cout << dp[i][j] << " ";
//    cout << endl;
//  }

  return 0;
}
