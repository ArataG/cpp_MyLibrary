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

/*
  累積和 + DP
*/

const int NMAX = 100+5;
const int KMAX = 1e5+5;
const int MOD = 1e9+7;
ll dp[NMAX][KMAX];
int main(){
  //#define int long long
  int n, k;
  cin >> n >> k;
  vector<int> a(n+1);
  REP(i,n) cin >> a[i];

  //REP(i,n+1) 
  dp[0][0] = 1;
  REP2(i, 1, n+1) {
    vector<int> cum(k+2);
    cum[0] = 0;
    REP(j,k+1){
      REP2(j,1,k+1) cum[j] = (cum[j-1] + dp[i-1][j-1])%MOD; 
      //cum[j]=dp[i-1][0]+...+dp[i-1][j-1]
      REP2(j,0,k+1) dp[i][j] = (cum[j+1]-cum[max(0,j-a[i])]+MOD)%MOD;
    }
  }
  cout << dp[n][k] << endl;

//debug
  REP(i,n+1){
    REP(j, k+1) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}