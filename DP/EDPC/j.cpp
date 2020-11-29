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

const int NMAX = 330;
double dp[NMAX][NMAX][NMAX];

int main(){
  //#define int long long
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  vector<int> cnt(3,0);
  REP(i,n) cnt[a[i]]++;

  REP(i,n+1) REP(j,n+1) REP(k,n+1){
    int sumCnt = i+j+k;
    if(sumCnt == 0) {
      dp[i][j][k] = 0;
      continue;
    }
    dp[i][j][k] = (double) n/sumCnt;
    if(i-1 >= 0) dp[i][j][k] += dp[i-1][j+1][k]*i/sumCnt;//３枚の皿から
    if(j-1 >= 0) dp[i][j][k] += dp[i][j-1][k+1]*j/sumCnt;//２枚の皿から
    if(k-1 >= 0) dp[i][j][k] += dp[i][j][k-1]*k/sumCnt; //1枚の皿から
  }
  
  
  double ans = dp[cnt[3]][cnt[2]][cnt[1]];
  cout << fixed << setprecision(15) <<ans << endl;
  return 0;
}

/*
  どの皿に何個あるか >> 1個の皿, 2個の皿, 3個の皿それぞれの個数がわかればよい.
  dp[c1][c2][c3] = 1個の皿がc1, 2個の皿がc2, 3個の皿がc3のときの操作回数の期待値.
  *+
  ループが再帰してしまうので, 式変形すると, 上のDPになる.
  

  **
  確率pのモノを, 引くまでに繰り返す時, 繰り返す回数の期待値は1/p
  https://www.youtube.com/watch?v=qM8dVMiOpIQ
*/