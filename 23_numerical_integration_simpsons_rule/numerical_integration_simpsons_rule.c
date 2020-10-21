#include <stdio.h>
#include <math.h>

#define f(x) (sqrt(4-(x)*(x)))  // 被積分関数の定義

void main(void) {

    double a, b;  // 積分区間[a, b]
    double n, h, fo, fe, sum;

    printf("input A and B ... [A, B] ");
    scanf("%lf %lf", &a, &b);

    n = 50;             // 区間の分割数
    h = (b-a) / (2*n);  // 区間幅h
    
    // 偶数項・奇数項の合計値の初期化
    fo = 0;
    fe = 0;

    // 各微小区間の面積を足し合わせる処理
    for(int k=1; k<=2*n-3; k=k+2) {
        fo = fo + f(a+h*k);      // 奇数項の和
        fe = fe + f(a+h*(k+1));  // 偶数項の和
    }
    sum = (f(a) + f(b) + 4*(fo+f(b-h)) + 2*fe) * h/3;

    // 計算結果の出力   
    printf("   /%f\n", b);
    printf("   |  sqrt(4-x*x) = %f\n", sum);
    printf("   /%f\n", a);
}
