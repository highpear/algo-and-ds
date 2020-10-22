#include <stdio.h>
#include <math.h>

double myexp(double);  // テイラー展開を用いるexp(x)

void main(void) {

    double x;
    // テイラー展開によるexp(x)と標準ライブラリ関数によるexp(x)の値を出力
    printf("    x      myexp(x)        exp(x)\n");
    for(x=0; x<=40; x=x+10) {
        printf("%5.1f%14.6g%14.6g\n", x, myexp(x), exp(x));
    }
}

double myexp(double x) {

    double EPS = 1e-08;  // 誤差の閾値
    double s = 1.0;      // (k-1)項までの和を初期化
    double e = 1.0;      // k項までの和を初期化
    double d;

    for(int k=1; k<=200; k++) {
        d = s;
        e = e * x / k;
        s = s + e;
        if(fabs(s-d) < EPS*fabs(d))  // 打ち切り誤差の判定
            return s;
    }
    return 0.0;  // 収束しないとき
}
