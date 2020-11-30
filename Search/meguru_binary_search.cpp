#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
  めぐる式二分探索
  以下の部分を書き換えるだけで使える.

  - ng 条件を満たさない値
  - ok 条件を満たす値
  - isOK 条件を記述

参考サイト: https://qiita.com/drken/items/97e37dd6143e33a64c8c
*/

vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};

//indexが条件を満たすかどうかの判定(x条件をここに書けばよい.)
//これは, lower_bound(x以上の最小のインデックスを返す)
bool isOK(int index, int key){
  if(a[index] >= key ) return true;
  else return false;
}

//ここは変わらない.
int meguru_binary_search2(int key) {
  int ng = -1;  //index=0が条件を満たすときも使えるように
  int ok = (int)a.size(); //index = a.size()-1 (配列の最終値)が条件を満たさないときも使えるように.
  while(abs(ng - ok) > 1){
    int mid = (ok + ng)/2;

    if(isOK(mid, key)) ok = mid; //関数isOK条件を記述する.
    else ng = mid;
  }
  return ok;
}

int main(){
  cout << meguru_binary_search2(243) << endl; // 6
  cout << meguru_binary_search2(15) << endl;  // 2
  cout << meguru_binary_search2(51) << endl;  // 3
  return 0;
}
