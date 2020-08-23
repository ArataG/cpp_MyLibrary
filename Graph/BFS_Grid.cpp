/**
  file   :  BFS_Grid.cpp 
  brief  :  迷路の最短距離をBFSで探す．height * widthの迷路．スタートとゴールの座標をセットする．
  author :  S.SUGIHARA
  date   :  2020-08-23
  update :
 */

/**
  参考資料：RASEN本(アルゴリズムとデータ構造)
  コードテスト：
*/

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;

/* 4 方向への隣接頂点への移動を表すベクトル */
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };


int main() {
    //input
    /* 縦と横の長さ */
    int height, width;
    cin >> height >> width;

    /* スタート地点とゴール地点 */
    int sx, sy, gx, gy;
    cin >> sx >> sy;
    cin >> gx >> gy;
    sx--,sy--,gx--,gy--;

    /* 盤面 */
    vector<string> field(height);
    for (int h = 0; h < height; ++h) cin >> field[h];

    // Init BFS
    // 各セルの最短距離 (訪れていないところは -1 としておく)
    vector<vector<int> > dist(height, vector<int>(width, -1));
    dist[sx][sy] = 0; // スタートを 0 に

    // 「一度見た頂点」のうち「まだ訪れていない頂点」を表すキュー
    queue<pair<int, int> > que;
    que.push(make_pair(sx, sy)); // スタートを push

    //Start BFS
    /* キューが空になるまで */
    while (!que.empty()) {
        pair<int, int> current_pos = que.front(); // キューの先頭を見る (C++ ではこれをしても pop しない)
        int x = current_pos.first;
        int y = current_pos.second;
        que.pop(); // キューから pop を忘れずに

        // 隣接頂点を探索:４方向// 8方向とかにもできる
        for (int dir = 0; dir < 4; ++dir) {
            int next_x = x + dx[dir]; //現在のｘ座標±１
            int next_y = y + dy[dir]; //現在のｙ座標±１

            //探索先が場外の場合
            if (next_x < 0 || next_x >= height || next_y < 0 || next_y >= width) continue; 

            //探索先が壁（＃）の場合
            if (field[next_x][next_y] == '#') continue; // 壁はダメ

            // まだ見ていない頂点なら push
            if (dist[next_x][next_y] == -1) {
                que.push(make_pair(next_x, next_y));
                dist[next_x][next_y] = dist[x][y] + 1;
            }
        }
    }

    //output 最短距離
    cout << dist[gx][gy] << endl;
    return 0;
}
