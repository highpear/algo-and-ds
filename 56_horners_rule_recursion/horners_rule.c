#include <stdio.h>

#define N 4  // 次数: 第4次の項まで計算

double fn(double, double *, int);

void main(void) {

    double a[] = {1, 2, 3, 4, 5};  // 係数配列

    printf("%f\n", fn(2, a, N));
}

// Hornerの方法の再帰版にて多項式を計算する
double fn(double x, double a[], int i) {

    if(i == 0) {
        return a[N];
    } else {
        return fn(x, a, i-1) * x + a[N-i];
    }
}
