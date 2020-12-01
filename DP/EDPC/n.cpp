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

/*
  区間dp + 累積和
*/

const int N = 440;
ll sum[N][N];
ll dp[N][N];
ll a[N];
static const ll LINF = 1e20;

int main(){
  //#define int long long
  int n;
  cin  >> n;
  REP(i,n) cin >> a[i];
  //累積和
  REP(l,n){
    sum[l][l+1] = a[l];
    REP2(r,l+2,n+1){
      sum[l][r] = sum[l][r-1] + a[r-1];
    }
  }

  //幅が小さい順にとく
  for(int width = 2; width <= n; width++){
    for(int l = 0; l+width <= n; l++){
      int r = l + width;
      dp[l][r] = LINF;
      for(int m = l + 1; m < r ; m++){
        dp[l][r] = min(dp[l][r], dp[l][m] + dp[m][r] + sum[l][r]);
      }
    }
  }
  cout << dp[0][n] << endl;
  return 0;
}


/*
- N匹のスライム, 

- 区間DP
dp[l][r] = [ l, r )のスライムを 1 体にするときの最小コスト

- 初期値
dp[i][i+1] = 0

- 最終値
ans = dp[0][n] 

- dp遷移
dp[l][r] = min(dp[l][m] + dp[m][r] + [l,m)のスライムと[m, r)スライムを合体させるコスト)

ここが, L - Dequeの問題では, 

```cpp
dp[l][r] = min(dp[l+1][r] - a[l], dp[l][r-1] - a[r-1]); (手番 = 次郎)
```
となっており, O[1] だったのに対し, 本問では, 区切りの位置 m の移動分のO[N]かかる点に注意する.

l < m < rについてminを取る.

- 範囲が小さい順から見る

*/