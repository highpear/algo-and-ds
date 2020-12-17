#include <stdio.h>

#define N 8  // 4N方陣 (n = 4, 8, 12, ...)

void main(void) {

    int board[N+1][N+1]; 

    for(int j=1; j<=N; j++) {
        for(int i=1; i<=N; i++) {  // 左上から右下へ順番に走査
            if(j%4 == i%4 || (j%4+i%4)%4 == 1) {
                board[i][j] = (N+1-i)*N - j + 1;  // 対角線上の要素
            } else {
                board[i][j] = (i-1)*N + j;        // 対角線上以外の要素
            }
        }
    }

    // 魔方陣の出力
    printf("        4N Magic Square (N=%d)\n", N);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            printf("%4d", board[i][j]);
        }
        printf("\n");
    }
}