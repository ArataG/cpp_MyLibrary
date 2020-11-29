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

//LCSと,dpの復元

const int NMAX = 3005;
int dp[NMAX][NMAX];

int main(){
  //#define int long long
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();

  //LCSの長さを求める.
  REP(i, n)
  {
    REP(j, m)
    {
      if (s[i] == t[j])
        dp[i + 1][j + 1] = dp[i][j] + 1;
      else
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
    }
  }
  //LCSの長さ
  //cout << dp[n][m] << endl;

  //dpを逆から復元: 周辺を探索して, dpが減らない方向に移動する.
  int len = dp[n][m];
  string ans;
  int is = s.size()-1, it = t.size()-1;
  //cout << s[is] << t[it] << endl;
  int cnt = 0;

  while (len>0)
  {
    if (s[is] == t[it]){
      ans += s[is];
      it--;
      is--;
      len--;
    }
    else {
      if(dp[is][it+1] > dp[is+1][it] > 0 ) is--; //dpが減らない方向に移動.
      else it --;
    }
    //cout << len << endl;
  }
  
  reverse(ALL(ans)); //逆順に追加しているので反転する.
  cout << ans << endl;
  return 0;
}


/*

添字がちゃみたいになっていてつらいな.

*/