/**
File   :  kurikaesi-2jouhou.cpp
Brief  :  繰り返し2乗法 O[logn]

実用上は，atcoder lib の，mint.cppを用いて，
mint x = mint(a).pow(n);
で計算できる．
**/

/**
Reference： https://math.nakaken88.com/textbook/cp-binary-exponentiation-and-recursive-function/
Code test： aのn乗を入力
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
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}


/*
 繰り返し2乗法の素朴な書き方．
*/

int modPow(ll a, ll n, ll p){
  //例外処理
  if(n==0) return 1;
  //再帰の終点
  if(n==1) return a%p;
  //n=(奇数の場合)
  if(n%2==1) return(a*modPow(a, n-1, p))%p;
  //n=（偶数の場合)
  ll t = modPow(a, n/2, p);
  return (t*t)%p;
}



int main(){
  ll a, n, mod;
  cin >> a >> n;

  /* 素朴な解き方*/
  mod = 1e9+7;
  ll ans = modPow(a,n,mod);
  cout << ans << endl;
  
  /*
  　　ライブラリの利用
  */
 mint ans2 = mint(a).pow(n);
 cout << ans2 << endl;

  return 0;
}