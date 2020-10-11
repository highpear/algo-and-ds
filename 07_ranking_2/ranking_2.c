#include <stdio.h>

#define NUM 10
#define MAX 100  // 得点の最大値
#define MIN 0    // 得点の最小値

void main(void) {

    int data[] = {56, 25, 67, 88, 100, 61, 55, 67, 76, 56};
    int rank[MAX+2];

    // ゼロ埋め
    for (int i=MIN; i<=MAX; i++)
        rank[i] = 0;

    // 全得点の度数をカウント
    for (int i=0; i<NUM; i++)
        rank[data[i]]++;

    rank[MAX+1] = 1;                    // 100点の順位は1位
    for (int i=MAX; i>=MIN; i--)        // 得点の高い方から低い方へ
        rank[i] = rank[i] + rank[i+1];  // 左の要素に加算結果を保存

    // 順位の表示
    printf(" score  rank\n");
    for (int i=0; i<NUM; i++) {
        printf("%6d%6d\n", data[i], rank[data[i]+1]);  // dataのi番目の順位はrankのi+1番目
    }
}
