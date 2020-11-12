#include <stdio.h>

long factorial(int);

void main(void) {

    int n;
    
    for(n=0; n<13; n++) {
        printf("%2d! = %10ld\n", n, factorial(n));
    }
}

// 再帰を用いずに階乗計算を行う関数
long factorial(int n) {

    long p = 1L;

    for(int k=n; k>=1; k--) {
        p *= k;
    }
    return p;
}
