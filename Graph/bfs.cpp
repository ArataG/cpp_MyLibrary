
//https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_C

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define DREP(i,n) for (int i = (n-1); i >=0; --i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;
//debug 
#ifdef _DEBUG
#define debug(var)  do{cout << #var << " :";view(var);}while(0)
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
  //#define int long long
  int n;
  cin >> n;
  vector<vector<int>> to(n);
  REP(i,n){
    int a, k;
    cin >> a >> k;
    --a;
    REP(j,k) {
      int b;
      cin >> b;
      --b;
      to[a].push_back(b);
      //to[b].push_back(b);
    }
  }
  debug(to);

  //bfs

  vector<int> d(n, -1);
  queue<int> q;
  //startの挿入
  q.push(0);
  d[0] = 0;

  while(!q.empty()){
    int now = q.front();q.pop();
    for(auto next : to[now]){
      if(d[next] != -1) continue;
      d[next] = d[now] + 1;
      q.push(next);
    }
  }
  
  REP(i,n){
    cout << i + 1 << " " << d[i] << endl;
  }
  return 0;
}