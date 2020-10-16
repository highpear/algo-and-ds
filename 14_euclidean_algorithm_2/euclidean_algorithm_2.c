#include <stdio.h>

int get_GCD(int, int);

void main(void) {

    int n1, n2, m, n;

    printf("input two integers >>");
    scanf("%d %d", &n1, &n2);

    m = n1;
    n = n2;
    printf("GCD = %d\n", get_GCD(m, n));  // 結果を表示
}

// 2つの整数の最大公約数を求める関数
int get_GCD(int m, int n) {
    
    int k;
    // 剰余を用いたユークリッドの互除法を適用
    do {  // do-whileを使うことで，kを初期化しなくて良くなる
        k = m % n;
        m = n;
        n = k;
    } while (k != 0);
    
    // ループを抜けるとmが最大公約数となっている
    return m;
}