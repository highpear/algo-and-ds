#include <stdio.h>
#include <math.h>

#define f(x) (sqrt(4-(x)*(x)))  // 被積分関数の定義

void main(void) {

    double a, b;  // 積分区間[a, b]
    double n, h, x, s, sum;

    printf("input A and B ... [A, B] ");
    scanf("%lf %lf", &a, &b);

    n = 50;         // 区間の分割数
    h = (b-a) / n;  // 区間幅h
    
    // 初期化
    x = a;
    s = 0;

    // 各台形の面積を足し合わせる処理
    for(int k=1; k<=n-1; k++) {
        x = x + h;
        s = s + f(x);
    }
    sum = h * ((f(a) + f(b)) / 2 + s);

    // 計算結果の出力
    printf("   /%f\n", b);
    printf("   |  sqrt(4-x^2) = %f\n", sum);
    printf("   /%f\n", a);
}
