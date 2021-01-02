#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;

//進数の文字列
string s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //36まで

void f(int n, int base){
  string ans;
  do{
    int pos = n%base;
    ans += s[pos];
    n /= base;
  }while(n > 0);
  reverse(ALL(ans));
  cout << ans << endl;
}

int main(){
  int BASE = 36; // x進数を指定 2 <= x <= 36;
  int n;
  cin >> n;
  f(n, BASE); 
  return 0;
}