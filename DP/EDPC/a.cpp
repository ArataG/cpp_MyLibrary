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

//N
//もらうDP
/*
  dp[0] = 0;
  dp[1] = abs(h[1] - h[0]);
  n >= 2
  //dp[i] = min(dp[i-2] + abs(h[i] - h[i-2]), dp[i-1] + abs(h[i] - h[i-1]));
*/

const int NMAX = 100'005;
int dp[NMAX];
int main(){
  int n;
  cin >> n;
  vector<int> h(n);
  REP(i,n) cin >> h[i];

  dp[0] = 0;
  dp[1] = abs(h[1] - h[0]);
  REP2(i,2,n){
    int cost1 = dp[i-1]+abs(h[i]-h[i-1]);
    int cost2 = dp[i-2]+abs(h[i]-h[i-2]);
    dp[i] = min(cost1,cost2);
  }

  cout << dp[n-1] << endl;
  //REP(i,n) cout << dp[i] <<" ";
  
  return 0;
}