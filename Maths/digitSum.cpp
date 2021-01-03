#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
using namespace std;
using ll = long long;

// 桁和を返す. int or String 
int digitSum(string s){
  int res = 0;
  REP(i,s.size()) res += s[i] - '0'; 
  return res;
}

int digitSum(int n){
  int res = 0;
  while(n > 0){
    res += n%10;
    n /= 10;
  }
  return res;
}

int main(){
  //string a;
  int  a;
  cin >> a;
  //桁和
  int sa = digitSum(a);
  cout << sa << endl; 
  return 0;
}