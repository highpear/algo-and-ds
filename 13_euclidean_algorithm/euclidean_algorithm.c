#include <stdio.h>

int get_GCD(int, int);

void main(void) {

    int n1, n2, m, n;

    printf("input two integers >>");
    scanf("%d %d", &n1, &n2);  // 入力された2つの整数の最大公約数を求める

    m = n1;
    n = n2;
    printf("GCD = %d\n", get_GCD(m, n));  // 結果の表示 
}

// 2つの整数の最大公約数を求める関数
int get_GCD(int m, int n) {
    // ユークリッドの互除法を適用
    while (m != n) {
        if (m > n) {
            m = m-n;
        }
        else {
            n = n-m;
        }
    }
    return m;  // ループを抜けるとm, 及びnが最大公約数となっている
}