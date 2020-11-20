/**
  file   : file-output.cpp
  brief  : ファイル(test2.cpp)に書き込み
 */

/**
  参考資料： やさしいc++
  コードテスト(CLI)： ./a.out test0.txt
*/

#include<iostream>
#include<fstream>

using namespace std;

int main(){
  ofstream fout("test2.txt");
  if(!fout){
    cout << "file does not open\n";
    return 1; 
  }
  else
    cout << "ファイルをopenしました\n";
  
  //書き込み
  fout << "HelloC++!\n";
  fout << "GoodbyeC++\n";

  cout << "ファイルに書き込みました\n";

  fout.close();
  cout << "ファイルをクローズしました\n";
  return 0;
}