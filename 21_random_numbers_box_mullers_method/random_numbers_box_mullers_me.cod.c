#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159 // 円周率
#define SIGMA 2.5  // 標準偏差
#define MU 10.0    // 平均

void brnd(double, double, double *, double *);

void main(void) {

    int hist[100];  // ヒストグラム用配列
    double x, y;

    // ヒストグラムを初期化 
    for (int i=0; i<100; i++) {
        hist[i] = 0;
    }

    for (int i=0; i<1000; i++) {
        brnd(SIGMA, MU, &x, &y);  // 正規乱数を生成する
        hist[(int)x]++;           // 度数をインクリメント
        hist[(int)y]++;           // 度数をインクリメント
    }

    for (int i=0; i<=20; i++) {   // ヒストグラムの表示
        printf("%3d : I ", i);
        for (int j=1; j<=hist[i]/10; j++) {
            printf("□");
        }
        printf("\n");
    }
}

// ボックス・ミュラー法により正規乱数を生成する
void brnd(double sig, double m, double *x, double *y) {

    double r1, r2;

    r1 = rand() / (RAND_MAX+0.1);
    r2 = rand() / (RAND_MAX+0.1);

    *x = sig * sqrt(-2 * log(r1)) * cos(2 * PI * r2) + m;  // 式(2)の計算
    *y = sig * sqrt(-2 * log(r1)) * sin(2 * PI * r2) + m;  // 式(3)の計算
}
