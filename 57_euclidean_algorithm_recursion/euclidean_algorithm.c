#include <stdio.h>

int gcd_sub(int, int);   // 差を用いた再帰版ユークリッドの互除法
int gcd_surp(int, int);  // 剰余を用いた再帰版ユークリッドの互除法

void main(void) {

    int a, b;

    printf("input 2 numbers >>");
    scanf("%d %d", &a, &b);

    printf("GCD = %d\n", gcd_sub(a, b));   // 差によるユークリッドの互除法
    printf("GCD = %d\n", gcd_surp(a, b));  // 剰余によるユークリッドの互除法 

}

// 差による
int gcd_sub(int m, int n) {

    if(m == n) {
        return m;
    }
    if(m > n) {
        return gcd_sub(m-n, n);
    } else {
        return gcd_sub(m, n-m);
    }
}

// 剰余による
int gcd_surp(int m, int n) {
    
    if(n == 0) {
        return m;
    } else {
        return gcd_surp(n, m%n);
    }
}
