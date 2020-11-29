# cpp_MyLibrary
自分用にc++のアルゴリズムをまとめています．

## Contents
 
### DP: 動的計画法

|ファイル名     |機能     |
|:------------|:-------|
|knapusack.cpp||
|EDPC/        |DP典型問題. ([AtCoderDPまとめコンテスト](https://atcoder.jp/contests/dp)のACコード): 更新中|


### DataStruct: データ構造

|ファイル名|機能|
|:-------|:-------|
|RAQ.cpp |セグメントツリーによる Range Add Query|
|RMQ.cpp |セグメントツリーによる Range Minimum Query|
|RSQ.cpp |セグメントツリーによる Range Sum Query|
|UnionFind.cpp|データを互いに素な集合(連結成分)ごとに分ける|
|UnionFind-getList.cpp|連結成分ごとのリストを返せるよう機能を追加|

### Geometry: 幾何

|ファイル名|機能|
|:-------|:-------|
|geometry-2d.cpp|二次元平面のライブラリ. TODO: しばらく触ってないので,使い方の再確認とテストが必要.|


### Graph: グラフ
|ファイル名|機能|
|:----------------|:-------|
|BFS_Grid.cpp     |迷路の最短距離をBFSで探索する．height * widthの迷路．スタートとゴールの座標をセットする|
|BFS_Matrix.cpp   |        |
|Dijkstra.cpp     |        |
|Kruskal.cpp      |        |
|WarshallFloyd.cpp|        |
|Topological_sort.cpp|有向非巡回グラフ(DAG)の各頂点を順序付け．どの頂点もその出力変の先のノードより前に来るように並べ替える|

### Maths:　数学
|ファイル名|機能|
|:------------|:-------|
|Eratos.cpp   |n以下の素数を列挙|
|isPrime.cpp  |素数判定|
|enum_divisor.cpp|n以下の約数を列挙|
|prime_factorize.cpp|n以下の素因数と素因数の個数を列挙|
|get_digit.cpp|整数nの桁数を返す(ただ10で割ってるだけ)|
|modPow.cpp|繰り返し2乗法を利用した累乗の計算|

### Search: 探索
|ファイル名|機能|
|:------------|:-------|
|BitSearch.cpp||
|permutation.cpp|順列全探索|

### Util: ユーティリティー
|ファイル名|機能|
|:------------|:-------|
|template.cpp |初期入力のためのテンプレート|
|mint.cpp|mod int|
|two-pointers.cpp|しゃくとり法|
|comb01.cpp|combination(n,a) nが大きく，aが小さい場合の計算|

### IOstream
|ファイル名|機能|
|:------------|:-------|
|file-input.cpp|ファイルを入力|
|file-output.cpp|ファイルを入力|
|command-line.cpp |コマンドライン引数を利用してファイル名を指定|


# Reference
- プログラミングコンテスト攻略のためのアルゴリズムとデータ構造, 渡部有隆, マイナビ出版, 2015
- atcoder　live_library
- YouTube(かつっぱ競プロ) https://www.youtube.com/channel/UCqqeYOh1gk_TJ16sxazWhUg
