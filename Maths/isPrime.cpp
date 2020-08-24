/**
File   :  isPrime.cpp
Brief  :  入力されて整数Nが素数かどうかを判定する．O[√x]
Author :  S.SUGIHARA
Date   :  2020-08-24
Update :
**/

/**
Reference： RASEN本
  [2以外の偶数は素数ではない]
  [合成数 x は P <= √x を満たす素因数 p を持つ] 素数の性質を利用
Code test： 調べたい整数Nを入力
*/
#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

//
int isPrime( int x) {
  int i;
  if(x < 2) return 0;
  else if (x == 2)  return 1;   //2は素数
  if (x % 2 == 0) return 0;     //2以外の偶数は素数ではない
  for(i = 3; i*i <= x; i += 2){ //P <= √x を満たす素因数 p を持つなら素数ではない
    if (x % i == 0) return 0;
  }
  return 1;
}



int main() {
  int n;
  cin >> n;
  if(isPrime(n)) cout << "Prime Num" << endl;
  else cout << "Not Prime Num" << endl;

  return 0;
}
