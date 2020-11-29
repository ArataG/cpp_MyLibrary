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

//配るDP?

const int NMAX = 100'005; 
//結構,桁を間違えるので,10e5+5とかに統一した方がいいかも?
//dp[1-N]に統一したほうがわかりやすい?dpを1indexから
int dp[NMAX];

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  REP(i,n) cin >> h[i];
  REP(i,n) dp[i] = INF;
  dp[0] = 0;
  REP(i,n){
    REP2(j,1,k+1){
      if(i+j > n-1) break; 
      int cost =  dp[i] + abs(h[i]-h[i+j]);
      dp[i+j] = min(dp[i+j], cost); 
    }
  }
  //ans
  cout << dp[n-1] << endl;
  //REP(i,n) cout << dp[i] <<" ";
  return 0;
}
