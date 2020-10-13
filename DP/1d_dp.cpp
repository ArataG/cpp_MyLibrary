/**
File   :  1d_dp.cpp
Brief  :  一次元DPについて
*/

/**
Reference： AtCoder EDP Contest
Code test： https://atcoder.jp/contests/dp/tasks/dp_a
*/

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
//入力
int n;

//DPテーブル
int dp[100100]; //dp[i]: 足場iでの最小コスト
int h[100100]; //足場の高さ

int main() {
  //input
  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> h[i];

  //DPの初期化
  dp[1] = 0;
  dp[2] = abs(h[2]-h[1]);

  //DPループ
  for(int i = 3; i <= n; ++i){
    dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]), dp[i-2]+abs(h[i]-h[i-2]));
  }

  cout << dp[n] << endl;
}