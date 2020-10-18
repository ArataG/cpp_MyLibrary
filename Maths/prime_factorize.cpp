/**
File   :  prime_factorize.cpp
Brief  :  素因数分解
**/

/**
Reference： RASEN本
  [2以外の偶数は素数ではない]
  [合成数 x は P <= √x を満たす素因数 p を持つ] 素数の性質を利用
Code test： 調べたい整数Nを入力
*/
#include <iostream>
#include <vector>
using namespace std;

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main() {
    long long n;
    cin >> n;
    const auto &res = prime_factorize(n);
    cout << "素因数：素因数の個数"<< endl;
    for (auto p : res) {
      cout << p.first << " : " << p.second << " 個"<<endl;
        //for (int i = 0; i < p.second; ++i) cout << " " << p.first;
    }
}