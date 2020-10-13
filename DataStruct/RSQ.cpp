/**
  file RSQ.cpp
  brief Range Sum Query: Segment Treeを利用してRange Sum Query(区間更新，一点取得）を行う． 
 */

/**
  参考資料：  https://www.youtube.com/watch?v=ReGvflPU81c&list=PL3Hpv03CoZ24p5a6qT0LsFKEhiDWxf_B_&index=4
  コードテスト(AOJ)：https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
*/

#include<iostream>
using namespace std;
using ll = long long;

//
#define SEG_LEN (1 << 18) //10^5 より大きい２進数, index = 1から利用する．
int seg[SEG_LEN * 2];

void add(int ind, int x){
  ind += SEG_LEN;
  seg[ind] += x;
  while(true){
    ind /= 2;
    if(ind == 0) break;
    seg[ind] = seg[ ind * 2 ]+seg[ ind * 2 + 1 ];
  }

}

int sum(int l, int r){
  l += SEG_LEN;
  r += SEG_LEN;
  long long ans = 0;
  while(l < r){
    if(l%2 == 1){
      ans += seg[l];
      l++;
    }
    l /= 2;

    if(r%2 == 1){
      ans += seg[r - 1];
      r--;
    }
    r /= 2;
  }
  return ans;
}

int main(){
  int n, q;
  cin >> n >> q;

  for(int i = 0; i < q; i++){
    int com;
    cin >> com;
    if(com == 0){//add
      int ind, x;
      cin >> ind >> x;
      add(ind, x);
    }

    if(com == 1){//get sum
      int l,r;
      cin >> l >> r;
      cout << sum(l,r+1) << endl;
    }
  }
  return 0;
}