#include <stdio.h>

void main(void) {

    int d;  // 割る数
    int n;  // 素因数分解される数 (=割られる数，逐次小さくなる)

    while(printf("input a number >>"), scanf("%d", &n) != EOF) {
        d = 2;  // 割る数の初期値は2
        
        while(n >= d*d) {
            if (n%d == 0) {  // 割り切れた段階で即時出力
                printf("%dx", d);
                n = n/d;     // 割り切れることが判明したのでnをdで割った値に更新
            } else {
                d++;         // 割り切れなかった場合，dをインクリメント
            }
        }

        printf("%d\n", n);   // 最後まで残った数を表示 (素数とは限らない)
    }
}
