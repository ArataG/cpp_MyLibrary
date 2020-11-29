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

  H-GRID 
*/

const int HMAX = 1e3+10;
const int WMAX = 1e3+10;
int dp[HMAX][WMAX];
int MOD = 1e9+7;

int main(){
  //#define int long long
  int H, W;
  cin >> H >> W;
  vector<string> field(H);
  REP(h,H) cin >> field[h];
  
  if(field[0][0] != '#') dp[0][0] = 1;

  REP2(h,1,H) if(field[h][0] != '#') dp[h][0] = dp[h-1][0];
  REP2(w,1,W) if(field[0][w] != '#') dp[0][w] = dp[0][w-1];

  REP2(i,1,H){
    REP2(j,1,W){
      if(field[i][j] == '#') dp[i][j] = 0;
      else dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
    }
  }

  cout << dp[H-1][W-1] << endl;
  
  //debug
  // REP(h,H){
  //   REP(w,W) cout<<dp[h][w] <<" ";
  //   cout << endl; 
  // }
  
  return 0;
}