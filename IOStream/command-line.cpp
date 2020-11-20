/**
  file   :  command-line.cpp
  brief  : コマンドライン引数で指定したファイルを開いて，読み込みを行う．
 */

/**
  参考資料： やさしいc++
  コードテスト(CLI)： ./a.out test0.txt
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
  if(argc != 2){
    cout << "パラメータの数が違います\n";
  }

  //ファイルを読み込み．ファイル名はargv[1]に記録されている．
  ifstream fin(argv[1]);
  if(!fin){
    cout << "file does not open\n";
    return 1;
  }

  char ch;
  fin.get(ch); //ファイルから一文字読み込む(空白や改行も含む)
  
  //ファイルが終わりに達するまで読み込みを繰り返す．
  while(!fin.eof()){
    cout.put(ch); //コンソールに出力する．
    fin.get(ch);
  }

  //ファイルを閉じる
  fin.close();

  //argv[0]には，実行ファイル名が入力されている．
  cout << "file name is "<< argv[0] << "\n";

  return 0;
}