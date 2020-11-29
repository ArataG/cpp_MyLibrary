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
dp[l][r] = 0; (if i == j )
dp[l][r] = max(dp[l+1][r] + a[l], dp[l][r-1] + a[r-1]); (手番 = first)
dp[l][r] = min(dp[l+1][r] - a[l], dp[l][r-1] - a[r-1]); (手番 = second)
*/

//区間DP

const int NMAX = 3005;
ll dp[NMAX][NMAX];

int main(){
  //#define int long long
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  REP(i,n) dp[i][i] = 0;
  
  //幅が短いものから順に
  for(int width = 1; width <= n; width++){
     for(int l = 0; l + width <= n; l++){
       int r = l + width;
       //first
       if(width%2 == n%2 )
         dp[l][r] = max(dp[l+1][r] + a[l], dp[l][r-1] + a[r-1]);
       else
         dp[l][r] = min(dp[l+1][r] - a[l], dp[l][r-1] - a[r-1]);
     }
  }

  cout << dp[0][n] << endl;
  
  return 0;
}