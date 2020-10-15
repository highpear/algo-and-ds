#include <stdio.h>
#include <stdlib.h>

#define NUM 1000  // 試行回数 (=生成する点の総数)

double rnd(void);

void main(void) {

    double x, y, s;
    int cnt_in = 0;  // 1/4楕円内の点をカウント

    // NUM個の点を生成
    for (int i=0; i<NUM; i++) {
        // ランダムにx, y座標を生成
        x = 2*rnd();  // 0～2
        y = rnd();    // 0～1

        // 1/4楕円内に存在するとき 
        if (x*x/4+y*y <= 1) {
            cnt_in++;
        }
    }

    // 楕円の面積を求めて出力
    s = 8.0*cnt_in/NUM;
    printf("S = %f\n", s);
}

double rnd(void) {
    return (double)rand()/(RAND_MAX+0.1);
}
