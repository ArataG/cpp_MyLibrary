/**
  file two_pointers.cpp
  brief しゃくとり法に利用する． 条件を満たす連続する区間の最小の長さ，最大の長さ，区間の数え上げなどに使う．
 */

/**
  参考資料： https://qiita.com/drken/items/ecd1a472d3a0e7db8dce
  コードテスト(atcoder)：https://atcoder.jp/contests/abc130/tasks/abc130_d
*/

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

int main(){
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];
  
  ll cnt = 0;
  ll right = 0, left = 0;
  ll sum = 0;
  REP(left,n){
    
    //右をすすめる
    while(1){
      //cout << sum << endl;
      if(right == n) break;
      if(sum >= k) break;
      sum += a[right];
      ++right;
     }
     //cout << left << ":" << right << ":" << sum << endl;
     //cout << sum << endl;
     if(sum >= k) {
       //cout << left << ":" << right << endl;
       cnt += (n+1 - right);
     }
     //if(sum >= k) cnt++;
     sum -= a[left];
     
    
  }

  cout << cnt << endl;
  return 0;
}