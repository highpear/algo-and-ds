#include <stdio.h>

// 以下，式(1)におけるパラメータ
#define A  109
#define C  1021
#define M  32768
#define X0 13

unsigned rndnum = X0;  // 初期値を設定

unsigned irnd(void);

void main(void) {
    // 生成した乱数を逐次表示 (100個まで)
    for(int j=0; j<100; j++) {
        printf("%8d", irnd());
    }
    printf("\n");
}

// 疑似乱数を生成して返す関数
unsigned irnd(void) {
    rndnum = (rndnum * A + C) % M;
    return rndnum;
}
