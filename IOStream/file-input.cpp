/**
  file   :  file-input.cpp
  brief  : ファイルを読み込み，配列に記録．データの最大値，最大値を取得
 */

/**
  参考資料： やさしいc++
  コードテスト(CLI)： ./a.out
  入力ファイル: test1.txt
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main(){
  ifstream fin("test1.txt");
  if(!fin){
    cout << "file does not open\n";
    return 1;
  }

  const int num = 8; //データ数
  int test[num]; //データを入力する配列
  // input data from file
  for(int i = 0; i < num; i++){
    fin >> test[i];
  }


  //output
  for(int i = 0; i < num ; i++){
    cout << "no." << i << setw(5) << test[i] << endl;
  }

  //get min and max
  int minx = 1e9;
  int maxx = 0;
  for(int i = 0; i < num; i++){
    minx = min(minx, test[i]);
    maxx = max(maxx, test[i]);
  }

  cout << "min; " << minx << endl;
  cout << "max; " << maxx << endl;

  return 0;
}