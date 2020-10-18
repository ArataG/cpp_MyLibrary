
/**
File   :  enum_divisor.cpp
Brief  :  N以下の約数の列挙を行う．
*/

/**
Reference： https://qiita.com/drken/items/a14e9af0ca2d857dad23
Code test： https://atcoder.jp/contests/abc180/tasks/abc180_c
整数nを入力すると，その約数を昇順に出力する．
*/

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<long long> enum_divisors(long long N) {
    vector<long long> res; // 約数を格納する配列
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push，重複なら外す．
            if (N/i != i) res.push_back(N/i); 
        }
    }
    // 約数を小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}


int main(){
  ll n;
  cin >> n;
  const auto &res = enum_divisors(n);
  for (int i = 0; i < res.size(); ++i) cout << res[i] << endl;
  
  return 0;
}