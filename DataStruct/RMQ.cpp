/**
  file RMQ.cpp
  brief Range Minimum Query: 再帰関数のSegment Treeを利用してRange Minimum Query(一点更新，区間取得)を行う．
  author S.SUGIHARA
  date 2020-08-23
  update
 
 */

/**
  参考資料：
  コードテスト(AOJ)：https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
*/

#include<iostream>
using namespace std;
using ll = long long;

ll INF = (1LL<<31) - 1;
ll seg[1 << 20];

void set_value(ll pos, ll val){
  pos += 1 << 19; //20?
  seg[pos] = val;
  while((pos /= 2) > 0 ){
    seg[pos] = min(seg[pos * 2], seg[pos * 2 + 1]);//自分の左右の子供のminをとって更新
  }
}

//クエリの右橋，左端，今いる場所の区間の左右端，今いる場所 デフォルト引数設定しとくとよい
ll get_min(ll ql, ll qr, ll sl = 0, ll sr = 1 << 19, ll pos = 1){
  //全くかぶっていないとき
  if(qr <= sl || sr <= ql) return INF;  //意味のない数字を返す　maxのときは，0を返す
  //完全にかぶっているとき（セグメントがクエリに）
  if(ql <= sl && sr <= qr) return seg[pos];
  //
  ll sm = (sl + sr) / 2;
  ll lmin = get_min(ql,qr,sl,sm,pos * 2); //左右の子に託す
  ll rmin = get_min(ql,qr,sm,sr,pos * 2 + 1); //左右の子に託す
  return min(lmin, rmin);
}

int main(){
  int n, q;
  cin >> n >> q;
  for(int i = 0; i < n; i++){
    set_value(i, INF);
  }



  for(int i = 0; i < q; i++){
    ll com, x, y;
    cin >> com >> x >> y;
      if(com == 0){
        set_value(x,y);
      }
      else{
        cout << get_min(x,y+1) << endl;
      }
  }

  return 0;
}
