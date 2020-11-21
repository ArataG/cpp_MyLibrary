/*
  nCk : nが大きく，aが小さいとき(1e5)の組み合わせの計算
  mint.cppが必要
  O[a]で計算できる．

  REFERENCE:https://atcoder.jp/contests/abc156/tasks/abc156_d
  
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

/*
  mint mod int
*/
const int mod = 1000000007;
//const int mod = 998244353;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1; //t==0なら1を返す
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);} //逆元
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

/*
  nCk : nが大きく，aが小さいとき(1e5)の組み合わせの計算
  mint.cppが必要
  O[a]で計算できる．
  
*/

mint choose(int n, int a){
  mint x = 1, y = 1; //x:分子，y:分母
  REP(i,a){
     x *= n-i;
     y *= i+1;
  }
  return x/y;
}

int main(){
  int n, a;
  cin >> n >> a;
  //n = 1000000000, a = 100000

  mint ans = choose(n,a);
  cout << ans.x << endl;
  return 0;
}