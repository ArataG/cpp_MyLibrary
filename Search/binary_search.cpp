#include <bits/stdc++.h>
using namespace std;


/*
  二分探索: 値の有無を判定する.
*/

vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};

bool my_binary_search(int key) {
  int left = 0;
  int right = (int)a.size() -1;
  while(right >= left){
    int mid = left + (right - left)/2;
    if(a[mid] == key ) return true;  //return midでkeyのindexを返せる.
    else if (a[mid] > key ) right = mid - 1;
    else if (a[mid] < key ) left  = mid + 1;
  }
  return false; //Not_Found
}

//indexが条件を満たすかどうかの判定(x条件をここに書けばよい.)
//これは, lower_bound(x以上の最小のインデックスを返す)
bool isOK(int index, int key){
  if(a[index] >= key ) return true;
  else return false;
}

//ここは変わらない.
int my_lower_bound(int key) {
  int left = -1;  //index=0が条件を満たすときも使えるように
  int right = (int)a.size(); //index = a.size()-1 (配列の最終値)が条件を満たさないときも使えるように.
  while(right - left > 1){
    int mid = left + (right - left)/2;

    if(isOK(mid, key)) right = mid; //関数isOK条件を記述する.
    else left = mid;
  }
  return right; //rightは常に条件を満たすように実装しているため
}




int main(){
  cout << my_binary_search(243) << endl; // 1
  cout << my_binary_search(15) << endl;  // 0
  //
  cout << my_lower_bound(243) << endl;  // 6
  cout << my_lower_bound(15) << endl;  // 2
  cout << my_lower_bound(51) << endl;  // 3

  return 0;
}

