
/**
File   :  get_digit.cpp
Brief  :  入力 n の桁数を返す.関数get_digit
*/



#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
using namespace std;
using ll = long long;


ll get_digit(ll num){
    ll digit=0;
    while(num!=0){
        num /= 10;
        digit++;
    }
    return digit;
}



int main(){

  ll n;
  cin >> n;
  ll ans = get_digit(n);
  cout << ans << endl;
  
  return 0;
}