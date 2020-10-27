#include <stdio.h>

double lagrange(double *, double *, int, double);

void main(void)
{
    // x,yの組のデータ
    double x[] = {0.0, 1.0, 3.0, 6.0, 7.0},
           y[] = {0.8, 3.1, 4.5, 3.9, 2.8};

    double t;  // tに対応する補間値を求める

    // 補間値の出力
    printf("      x      y\n");
    for(t=0.0; t<=7.0; t=t+0.5) {
        printf("%7.2f%7.2f\n", t, lagrange(x, y, 5, t));
    }
}

// ラグランジュの補間多項式より，tに対応すcる補間値sを求める関数
double lagrange(double *x, double *y, int n, double t) {  // 式(1)におけるxはt

    double s = 0.0, p;

    for(int i=0; i<n; i++) {
        p = y[i];                                    // 式(1)におけるy_iの値を取得
        for(int j=0; j<n; j++) {
            if(i != j) {                             // i=jを含めない
                p = p * (t - x[j]) / (x[i] - x[j]);  // 内側のΣを計算
            }
        }
        s = s + p;                                   // 各項を加算していく
    }
    return s;
}
