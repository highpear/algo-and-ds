#include <stdio.h>
#include <stdlib.h>

#define N 20  // 1～20のランダムな順列を生成する

int randn(int);

void main(void) {

    int tmp;        // 交換用一時記憶変数
    int perm[N+1];  // ランダムな順列を生成する為の配列

    // 配列の要素を各indexで初期化する
    for (int i=1; i<=N; i++) {
        perm[i] = i;
    }

    // 生成した乱数に従って要素を交換
    for (int i=N; i>1; i--) {
        int j = randn(i-1);
        tmp = perm[i];
        perm[i] = perm[j];
        perm[j] = tmp;
    }

    // 生成した順列を表示 (indexは1から)
    for (int i=1; i<=N; i++) {
        printf("%d ", perm[i]);
    }
    printf("\n");
}

int randn(int n) {
    return (int)(rand()/(RAND_MAX+0.1)*n+1);
}
