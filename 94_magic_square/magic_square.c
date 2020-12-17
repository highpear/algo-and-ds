#include <stdio.h>

#define N 7  // nは奇数 

void main(void) {

    int board[N+1][N+1];  // 添字を合わせるため1余分に確保
    int i, j, k;  // i, j は順に行，列

    j = (N + 1) / 2;  // 中心位置を導出
    i = 0;

    for(k=1; k<=N*N; k++) {  // すべてのマス分繰り返し
        if((k%N) == 1) {
            i++;
        } else {
            i--;
            j++;
        }

        if(i == 0) {  // iが上部へはみ出した時
            i = N;    // 同列最下行へ 
        }
        if(j > N) {   // jが右へはみ出した時
            j = 1;    // 同行左端へ
        }
        // 上記で求めたマス(i, j)にkを代入
        board[i][j] = k;
    }

    // 魔方陣の出力
    printf("        Magic Square (N=%d)\n", N);
    for(i=1; i<=N; i++) {
        for(j=1; j<=N; j++) {
            printf("%4d", board[i][j]);
        }
        printf("\n");
    }
}
