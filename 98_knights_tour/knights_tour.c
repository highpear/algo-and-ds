#include <stdio.h>

void backtrack(int, int);

#define N 5  // 5x5の盤面 (N=8以上で計算時間が膨大になる)

int m[N+4][N+4],  // 盤面を表す配列 (+4はナイトが範囲外にアクセスしないようにするためのマージン)
    dx[8] = {2, 1, -1, -2, -2, -1, 1, 2},  // ナイトが移動できる x成分
    dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};  // ナイトが移動できる y成分

void main(void) {

    // 盤面の初期化
    for(int i=0; i<=N+3; i++) {
        for(int j=0; j<=N+3; j++) {
            if(2<=i && i<=N+1 && 2<=j && j<=N+1) {
                m[i][j] = 0;  // 盤面
            } else {
                m[i][j] = 1;  // 壁 (訪れないマス)
            }
        }
    }

    // (2, 2)からバックトラッキングを実行 (壁を考慮)
    backtrack(2, 2);
}

// バックトラッキングにより，騎士巡歴問題を解く関数
void backtrack(int x, int y) {

    static int count = 0, num = 0;  // 訪問順をカウントする変数と，解の個数をカウントする変数

    if(m[x][y] == 0) {      // 訪問可能なマスならば
        m[x][y] = ++count;  // 訪問順番の記録
        if(count == N*N) {  // 全てのマスを巡歴した時
            // 解の出力
            printf("\n解%d\n", ++num);   // 解の数の表示
            for(int i=2; i<=N+1; i++) {  // 訪問順を格子状に出力
                for(int j=2; j<=N+1; j++) {
                    printf("%4d", m[i][j]);
                }
                printf("\n");
            }
        } else {  // 8種類の手を試しながら，訪問順を求める
            for(int k=0; k<8; k++) {
                backtrack(x+dx[k], y+dy[k]);
            }
        }

        m[x][y] = 0;  // 1つ前に戻る (訪問していないことにする)
        count--;
    }
}
