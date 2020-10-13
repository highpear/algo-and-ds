#include <stdio.h>

#define NUM  10         // データ数：例として10人のスコア
#define MAX  36         // スコアの最大値
#define MIN  -20        // スコアの最小値 (この値は必ず1位)
#define BIAS 1-(MIN)    // 最小値を配列要素の1に対応させる = 21

void main(void) {

    int data[] = {-3, 2, 3, -1, -2, -6, 2, -1, 1, 5};  // 10人分のスコアデータ
    int rank[MAX+BIAS+1];                              // 順位付けを行う為の配列 (スコアの数+1分を確保)

    // ゼロ埋め
    for (int i=MIN+BIAS; i<=MAX+BIAS; i++) {
        rank[i] = 0;
    }

    // スコアの度数をカウント
    for (int i=0; i<NUM; i++) {
        rank[data[i]+BIAS]++;
    }

    // 順位を計算
    rank[0] = 1;  // 最も小さいスコアは必ず1位
    for (int i=MIN+BIAS; i<=MAX+BIAS; i++) {
        rank[i] = rank[i] + rank[i-1];
    }

    // 順位の表示
    printf(" score  rank\n");
    for (int i=0; i<NUM; i++) {
        printf("%6d%6d\n", data[i], rank[data[i]+BIAS-1]);  // スコアと順位のシフト分に注意する
    }
}
