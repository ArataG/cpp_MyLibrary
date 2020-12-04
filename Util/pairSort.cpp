#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;

/*

  vector<pair<int,int>> のソート
  文字列の昇順, 降順とかはどうやるんだろう?

*/

int main(){
  //#define int long long
  vector<int> a = {1, 2, 3, 3, 3, 6};
  vector<int> b = {101, 102, 103, 104, 105, 106};
  vector<pair<int,int>> p;

  REP(i,6) p.emplace_back(a[i], b[i]);
  sort(ALL(p));
  cout << "<昇順, 昇順>" << endl;
  for(auto x: p) cout << x.first << " " << x.second << " " << endl;

  sort(RALL(p));
  cout << "<降順, 降順>" << endl;
  for(auto x: p) cout << x.first << " " << x.second << " " << endl;

  cout << "<昇順, 降順>" << endl;
  vector<pair<int,int>> p3;
  REP(i,6) p3.emplace_back(a[i], -b[i]); 
  sort(ALL(p3));
  for(auto x: p3) cout << x.first << " " << -x.second << " " << endl;

  cout << "<降順, 昇順>" << endl;
  vector<pair<int,int>> p4;
  REP(i,6) p4.emplace_back(-a[i], b[i]); 
  sort(ALL(p4));
  for(auto x: p4) cout << -x.first << " " << x.second << " " << endl;

  return 0;
}