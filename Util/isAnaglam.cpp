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
  アナグラムの判定
*/

int isAnagram(string s, string t){
  if(s.size() != t.size()) return 0; //サイズが違う.
  sort(ALL(s));
  sort(ALL(t));
  if(s != t) return 0;
  return 1;
}

int main(){
  int n;
  cin >> n;
  string t = "indeednow";

  REP(i,n){
    string s;
    cin >> s;
    if(isAnagram(s, t)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}