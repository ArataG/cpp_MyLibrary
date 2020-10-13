/**
File   :  eratos.cpp
Brief  :  N以下の素数の列挙を行う．エラトステネスの篩のアルゴリズムを用いる．O[N log(N)]
*/

/**
Reference： RASEN本　アルゴリズムとデータ構造
Code test： 整数Nを標準入力．約数が列挙される．
*/


#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

//
void Eratos(int n){
  int i;
  ++n;
  int isprime[n];
  for(i = 0; i < n; i++){
    isprime[i] = 1;
  }

  isprime[0] = isprime[1] = 0;

  for(i = 2; i*i <= n; ++i){
    if(isprime[i]){
      int j = i + i;
      while(j <= n){
        isprime[j] = 0; //iの倍数を除去
        j = j + i;
      }
    }
  }
  for(i = 0; i <= n; i++){
    if(isprime[i]) cout << i << endl;
  }

}
int main() {
  int n;
  cin >> n;
  cout << n << "以下の約数を列挙します..." << endl;
  Eratos(n);
}
