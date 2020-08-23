/**
  file   :  BitSearch.cpp 
  brief  :  bit全探索を行う．
  author :  S.SUGIHARA
  date   :  2020-08-23
  update :
 */

/**
  参考資料： https://qiita.com/drken/items/7c6ff2aa4d8fce1c9361
  コードテスト： コンパイルして実行 
*/


#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;

int main() {
  int n = 3;//bit数

  //i = 000 to 111までの全探索
  REP(i, 1<<n ){ 
    vector<int> d(n);  
    REP(j,n) if(i >> j&1){  //i の j ビット目が１であるかの判定
      d[j] = 1;
      //ここに処理を書く
    }
    //出力確認
    REP(i,n) cout << d[i];
    cout << endl;
  }
}
