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

const int NMAX = 1e5+5;
int dp[NMAX];

int main(){
  //#define int long long
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  //dp[0] = 0;  //firstが負ける状態を0とする.
  
  REP2(i,1,k+1){
    REP(j,n){
      if(i - a[j] < 0) continue;//i - a[j] < 0のときは操作できない == 負けの手番.
      if(dp[i-a[j]] == 0) dp[i] = 1;   //相手を負かす手番が一つあれば勝利.
    }
  }

  if(dp[k]) cout << "First" << endl;
  else cout << "Second" << endl;
  return 0;
}