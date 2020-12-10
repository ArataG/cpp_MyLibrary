#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define REP(i,n) for (int i = 0; i <(n); ++i)

/*
  printデバック用
  
  g++ <ファイル名> -D_DEBUG
  
  上記のようにオプションをつけてコンパイルした場合のみ出力される.
  
  main関数内

  debug(変数);
  
  で値を見たい変数をチェックできる.

*/


//debug 
#ifdef _DEBUG
#define debug(var)  do{cout<< "[" << #var << "]: ";view(var);}while(0)
#else
#define debug(...)
#endif
template<typename T> void view(T e){cout << e << endl;}
template<typename T> void view(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}
template<typename T> void view(const vector<vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<typename T1, typename T2> void view(pair<T1,T2> e) { cout << "("<< e.first << ", " << e.second <<")"  << endl;} 
template<typename T1, typename T2> void view(const vector<pair<T1,T2>>& v) {for(const auto& e: v){view(e);}}
// end debug


int main(){

  cout << "int型のdebug..." << endl;
  int a = 10;
  debug(a);
  cout << endl;

  cout << "long long 型のdebug..." << endl;
  long long la = 10;
  debug(la);
  cout << endl;

  cout << "double 型のdebug..." << endl;
  double da = 0.01;
  debug(da);
  cout << endl;


  cout << "string型のdebug..." << endl;
  string s = "abcaba";
  debug(s);
  cout << endl;

  cout << "vector<int>型のdebug..." << endl;
  vector<int> v = {0, 1, 2, 3, 4};
  debug(v);
  cout << endl;

  cout << "vector<vector<int>>型のdebug..." << endl;
  vector<vector<int>> vv ={{11,12,13}, {21,22,23}, {31,32,33}};
  debug(vv);
  cout << endl;

  cout << "pair<int, int>型のdebug..." << endl;
  pair<int,int> p(1,10);
  debug(p);
  cout << endl;

  cout << "pair<string, int>型のdebug..." << endl;  
  pair<string, int> sp;
  sp = make_pair(s, a);
  debug(sp);
  cout << endl;

  cout << "vector<pair<int, int>>型のdebug..." << endl;  
  vector<pair<int,int>> vp;
  REP(i,5) vp.emplace_back(i,i*5); //input
  debug(vp);
  cout << endl;

  return 0;
}
