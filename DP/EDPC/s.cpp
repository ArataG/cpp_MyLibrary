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

桁DP

*/
const int K_MAX = 1e5+5;
const int D_MAX = 110;
ll dp[K_MAX][D_MAX][2];
const int MOD = 1e9+7;

int main(){
  string K;
  int d;
  cin >> K;
  cin >> d;

  int n = K.size();

  dp[0][0][1] = 1;

  REP2(i,1,n+1){
    REP(j,d){
      int digit = K[i-1] - '0';
      REP(k, 10){
        dp[i][j][0] += dp[i-1][((j-k)%d + d)%d][0];
        if( k < (K[i-1] - '0')) dp[i][j][0] += dp[i-1][((j-k)%d+d)%d][1];
        dp[i][j][0] %= MOD;
      }
        dp[i][j][1] = dp[i-1][((j-digit)%d+d)%d][1];
    }
  }
  cout << (dp[n][0][0] + dp[n][0][1] + MOD -1)%MOD << endl;
  return 0;
}

/*

  1以上 K以下の整数について,
  各桁の数字の総和がDの倍数であるようなもの個数を求めよ.
 MOD = 10^9+7
 - 制約
 1≤K<10^10000

- dp状態
dp[i][j][c] = 上からi桁目までの, 桁和%Dがjであり
c = 今まで決めた部分がKと一致しているかどうか. 

- 初期値
dp[0][0][1] = 1

- dp遷移
dp[i][j][0] = ∑(dp[i-1][(j-k)%d][0]) + ∑(dp[i-1][(j-k)%d][1]) (if(k < K[i])) 
dp[i][j][1] = dp[i-1][(j-k) % d][1]

c = 0 一致しているとき
c = 1 一致している時
- 計算量
O[K*D*2] = 10^5*100*2 = 10^7

dp遷移で 0 <= k <= 9 より, 10ループくらい
よって, 10^8

 */