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
const int VMAX = 10e5+5;
ll dp[NMAX][VMAX]; 

int main(){
  //#define int long long
  int N, W;
  cin >> N >> W;
  vector<int> w(N+1); 
  vector<int> v(N+1);
  REP2(i,1,N+1) cin >> w[i] >> v[i];

  REP(i,N+1) REP(j,VMAX) dp[i][j] = INF;
  dp[0][0] = 0;
  
  REP2(i, 1, N+1){
    REP2(j, 0, VMAX+1){
      if(j-v[i] >= 0) dp[i][j] = min(dp[i-1][j], dp[i-1][j - v[i]]+ w[i]);
      else dp[i][j] = dp[i-1][j]; 
    }
  }
  int ans = 10e5;
  while(dp[N][ans] > W) ans--;
  cout << ans << endl;
  //REP(j, N+1) REP(i,W+1) {cout << dp[j][i] << " "; if(i == W) cout << endl;}
  return 0;
}

/*
//制約に注目する
1. item数, 価値, 重さの3つ.
状態として持てるのは,制約に注目すると, item数と価値しか無い.

//
2. dp[i][j][k]=(i番目までの品物を、価値がj、重さがkとなるように選べるか？)
ここで「『はい』か『いいえ』を値に持つようなDPは、添字を1つ選んで「～が『はい』になる〇〇の最小値(最大値)」という形に書き直せることが多い」

3. 「～となる〇〇の最大値」を値に持つDPは、適当な添字と入れ替えて「～となる××の最小値」というDPにできることが多いのだ！
*/