#include <stdio.h>

#define NUM 10  // データの個数

void main(void) {

    int data [] = {56, 25, 67, 88, 100, 61, 55, 67, 76, 56};
    int rank[NUM];

    for (int i=0; i<NUM; i++) {
        rank[i] = 1;  // 順位の初期値を1で初期化
        for (int j=0; j<NUM; j++) {
            if (data[j] > data[i])  // 自身を超える得点がある度に順位をインクリメント
                rank[i]++;
        }
    }

    printf(" score  rank\n");
    for (int i=0; i<NUM; i++) {
        printf("%6d%6d\n", data[i], rank[i]);
    }
}
