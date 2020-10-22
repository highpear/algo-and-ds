#include <stdio.h>
#include <math.h>

double mycos(double);  // テイラー展開で近似計算を行う関数cos(x)

void main(void) {

    double x;  //  x[deg.]
    double rd = 3.14159 / 180;  // [deg.] -> [rad.]の変換に使用 (usage: rad.=deg.*rd)

    printf("    x      mycos(x)        cos(x)\n");
    for(x=0; x<=180; x=x+10) {
        printf("%5.1f%14.6f%14.6f\n", x, mycos(x*rd), cos(x*rd));  // 両関数ともxは[rad.]で与える
    }
}

double mycos(double x) {  // 引数はx[rad.]

    double EPS = 1e-08;  // 誤差の閾値
    double s = 1.0;      // (k-1)項までの和を初期化
    double e = 1.0;      // k項までの和を初期化
    double d;

    x = fmod(x, 2 * 3.14159265358979);   // xの値を0～2πに収める (周期2πの余剰を計算)
    for(int k=1; k<=200; k=k+2) {        // 式(1)より，奇数項のみ計算
        d = s;                           // 前項までの和を保存
        e = -e * x * x / (k * (k + 1));  // 現在の項を計算 (前項に公比を掛けて計算)
        s = s + e;                       // 現在の項を加算して総和を求める
        if(fabs(s-d) < EPS * fabs(d)) {  // 打ち切り誤差の判定
            return s;
        }
    }
    return 9999.0;  // 収束しないとき
}
