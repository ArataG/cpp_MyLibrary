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
  bitDP
*/

const int MOD = 1e9+7;
const int SMAX = 1 << 21;
const int NMAX = 23;
ll dp[SMAX];
int a[NMAX][NMAX];
ll bitcnt[SMAX];

int main(){
  //#define int long long
  int n;
  cin >> n;
  REP(i,n)REP(j,n) cin >> a[i][j];
  
  dp[0] = 1;
  for(int s = 1; s < (1<<n); s++){
    //bitcnt[s] = bitcnt[s/2] + s%2; // これでもbitの数数えられるぽい,
    bitcnt[s] = __builtin_popcount(s); //1が立っているビット数を返す.= 人数
    for(int l = 0; l < n; l++){
      if((s >> l) % 2  == 0) continue; //そもそ女性がいないときは飛ばす. 
      dp[s] += dp[s - (1 << l)] * a[bitcnt[s] - 1][l];
      // a[男性][女性]の相性が1なら加算される.
      dp[s] %= MOD;
    }
  }
  cout << dp[(1<<n) - 1] << endl;  
  return 0;
}

/*
 -  N人の男性, N人の女性
 - 男性女性の相性を表す, N * Nの二次元配列 a が与えられる.
 - aij = 0 のとき,相性✗
 - aij = 1 のとき,相性○

  相性がいいペアをN組作る方法が何通りになるか求めよ. MOD = 10^9+7


  - dp[i][S] = 左からi人の男性と,女性の部分集合Sでマッチングする場合の数.
  >>>> dp[S] = 左からbitCnt[S]人の男性と,女性の部分集合Sでマッチングする場合の数.
  EX:) S = 011010ならば, bitcnt[S] = 3となり,男性が3人となることがわかる.

  - dp遷移
  
  - 初期値
dp[φ] = 1
//空集合のときに1になることに注意する. マッチングがないという, 正当な状態が一つ存在するため

dp[S] = ∑ dp[S/l] * a[bitcnt[S] - 1] [l]
l E S について総和を取る.
S/l :女性
a[bitcnt[S] - 1] [l]

a = 0 or 1なので, 掛け算するだけでマッチング数がわかる.
- 1 indexにすることを注意,
  - 

*/