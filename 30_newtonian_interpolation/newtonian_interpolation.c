#include <stdio.h>

double newton(double *, double *, int, double);

void main(void) {

    // x,yの組のデータ
    double x[] = {0.0, 1.0, 3.0, 6.0, 7.0},
           y[] = {0.8, 3.1, 4.5, 3.9, 2.8};

    double t;  // tに対応する補間値を求める

    // 補間値の出力
    printf("      x      y\n");
    for(t=0.0; t<=7.0; t=t+.5) {
        printf("%7.2f%7.2f\n", t, newton(x, y, 5, t));
    }
}

// ニュートン補間より，tに対応する補間値sを求める関数
double newton(double x[], double y[], int n, double t) {

    static int flag = 1;   // 初回のcallを判定する為のフラグ
    static double a[100];  // 係数配列，a_0～a_(n-1)を格納する
    double w[100];         // 係数aを求める為の作業用配列
    double s;

    // 初回のcallで係数a_0～a_(n-1)を求めてa[]に格納
    if(flag == 1) {        
        for(int i=0; i<n; i++) {
            w[i] = y[i];
            for(int j=i-1; j>=0; j--) {
                w[j] = (w[j+1] - w[j]) / (x[i] - x[j]);
            }
            a[i] = w[0];
        }
        flag = -1;
    }

    // ここで係数a_0～a_(n-1)は導出済み
    s = a[n-1];  // x=tにおける補間
    for(int i=n-2; i>=0; i--) {
        s = s * (t - x[i]) + a[i];  // hornerの方法により計算
    }
    return s;
}
