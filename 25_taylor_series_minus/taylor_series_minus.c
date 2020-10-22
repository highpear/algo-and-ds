#include <stdio.h>
#include <math.h>

double myexp(double);  // テイラー展開で近似計算を行う関数exp(x)

void main(void) {
 
    double x;
    printf("    x       myexp(x)        exp(x)\n");
    for(x=-40; x<=40; x=x+10) {  //xが負である計算も行う
        printf("%5.1f%14.6g%14.6g\n", x, myexp(x), exp(x));
    }
}

double myexp(double x) {  // テイラー展開を用いてexp(x)の近似計算を行う関数

    double EPS = 1e-08;   // 誤差の閾値
    double s = 1.0;       // (k-1)項までの和を初期化
    double e = 1.0;       // k項までの和を初期化
    double d, a;          // aはxの絶対値

    a = fabs(x);          // xは必ず正の値で計算し，後で正負に応じて処理を分岐
    for(int k=1; k<=200; k++) {
        d = s;
        e = e * a / k;
        s = s + e;
        if(fabs(s-d) < EPS*fabs(d)) {  // 打ち切り誤差の判定
            if(x>0) {
                return s;
            }
            else {
                return 1.0 / s;  // xが負の場合，正の値で計算したので逆数で返す
            }
        }
    }
    return 0.0;  // 収束しないとき
}
