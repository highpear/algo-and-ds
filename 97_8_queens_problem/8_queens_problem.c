#include <stdio.h>

#define N 8  // 8x8の盤面

void backtrack(int);

// クイーンの存在判定に用いる配列 (0: クイーンが存在, 1: クイーンが存在しない(初期値))
int column[N+1],  // 同じ列に存在するか
    rup[2*N+1],   // 右上がりの対角線上に存在するか
    lup[2*N+1],   // 左上がりの対角線上に存在するか
    queen[N+1];   // インデックスに対応する行におけるクイーンの位置を記録

void main(void) {

    // クイーンが不在として初期化
    for(int i=1; i<=N; i++) {
        column[i] = 1;
    }

    for(int i=1; i<=2*N; i++) {
        rup[i] = lup[i] = 1;
    }

    backtrack(1);  // 1行目からバックトラッキングを開始
}

// 8王妃問題のバックトラッキングを行う関数
void backtrack(int i) {

    static int num = 0;  // 解の数をカウント

    if(i > N) {  // 第i行の処理が終了 (解の出力)
        printf("\n解 %d \n", ++num);  // 解の数を出力
        for(int y=1; y<=N; y++) {     // 解の盤面を格子状に出力
            for(int x=1; x<=N; x++) {
                if(queen[y] == x) {  // 第y行のクイーンの位置はx列
                    printf(" Q");
                } else {  // クイーン以外はドットを表示
                    printf(" .");
                }
            }
            printf("\n");
        }
    } else {  // バックトラッキング
        for(int j=1; j<=N; j++) {  // j列目を調べる
            if(column[j] == 1 && rup[i+j] == 1 && lup[i-j+N] == 1) {  // j列目に存在できる条件
                queen[i] = j;  // 第i行のクイーンの位置をj列として記録
                column[j] = rup[i+j] = lup[i-j+N] = 0;  // 局面の更新 (クイーンを置いた位置を0とする)
                backtrack(i+1);  // 再帰呼び出しで次の行へ
                column[j] = rup[i+j] = lup[i-j+N] = 1;  // 局面の戻し (確定したクイーンの位置を変更)
            }
        }
    }
}
