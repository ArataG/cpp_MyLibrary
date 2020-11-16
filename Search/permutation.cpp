/**
  file permutation.cpp
  brief 順列全探索
 */

/**
  参考資料： https://algo-logic.info/permutation/
  コードテスト(AOJ)：整数nを入力
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> one_case;
    for (int i = 0; i < n; i++) { // one_case = {0,1,2,3,...n-1} とする
        one_case.emplace_back(i);
    }
    do {
        for (auto num : one_case) {
            //ここに処理を書く．
            cout << num << " ";
        }
        cout << endl;
    } while (next_permutation(one_case.begin(), one_case.end()));
    // 順列の最後になるまで one_case を並び替えながらループ
    return 0;
}