/**
  file RAQ.cpp
  brief Range Add Query: Segment Treeを利用してRange Add Query(区間更新，一点取得）を行う．
  author S.SUGIHARA
  date 2020-08-23
  update
 
 */

/**
  参考資料：  https://www.youtube.com/watch?v=ReGvflPU81c&list=PL3Hpv03CoZ24p5a6qT0LsFKEhiDWxf_B_&index=4
  コードテスト(AOJ)：https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
*/


#include <bits/stdc++.h>
using namespace std;

//
#define SEG_LEN (1 << 18) //10^5 より大きい２進数, index = 1から利用する．
int seg[SEG_LEN * 2];

//one point 取得
long long int get(int ind){
  ind += SEG_LEN;
  long long int sum = 0;
  sum += seg[ind];
  while(true){
    ind /= 2;
    if(ind == 0) break;
    sum += seg[ind];
  }
  return sum;
}

void add(int l, int r, int x){
  l += SEG_LEN;
  r += SEG_LEN;
    while(l < r){
    if(l%2 == 1){
      seg[l] += x;
      l++;
    }
    l /= 2;

    if(r%2 == 1){
      seg[r - 1] += x;
      r--;
    }
    r /= 2;
  }
}

int main(){
  int n, q;
  cin >> n >> q;

  for(int i = 0;i < q ; i++){
    int com;
    cin >> com;
    if(com == 0){//add
      int l, r, x;
      cin >> l >> r >> x;
      add(l, r+1, x);
    }

    if(com == 1){//get
      int ind;
      cin >> ind;
      cout << get(ind) << endl;

    }
  }


  return 0;
}