#include <stdio.h>
#include <stdlib.h>

#define NUM 1000  // 試行回数 (=生成する点の座標の個数)

double rnd(void);

void main(void) {

    double x, y;     // 生成する点のx座標，y座標
    double pi;       // 求める円周率
    int cnt_in = 0;  // 1/4円内に存在する点の総数をカウント

    // NUM個の一様の座標を生成する
    for (int i=1; i<=NUM; i++) {
        x = rnd();
        y = rnd();
        if (x*x+y*y <= 1) {  // 1/4円の境界および内部に存在する点をカウント
            cnt_in++;
        }
    }

    // 比の式から円周率を求める
    pi = (double)4*cnt_in/NUM;
    printf("π = %f\n", pi);
}

// 0～1の実数乱数を生成する
double rnd(void) {
    return (double)rand()/(RAND_MAX+0.1);
}
