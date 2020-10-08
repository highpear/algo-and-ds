#include <stdio.h>

double fn(double, double *, int);

void main() {

    // a_nを設定
    double a[] = {1, 2, 3, 4, 5};
    double n = 4;
    double x = 5;

    // 計算結果を表示
    printf("fn(%f)=%f\n", x, fn(x, a, n));

}

// Hornerの方法にて多項式を計算する
double fn(double x, double *a, int n) {

    double ans;

    ans = *(a+n);

    for(int i=n-1; i>=0; i--) {
        ans = ans * x + (*(a+i));
    }

    return ans;
}
