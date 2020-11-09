#include <stdio.h>

long factorial(int);

void main(void) {

    int n;

    // 12の階乗まで求める
    for(n=0; n<13; n++) {
        printf("%2d! = %10ld\n", n, factorial(n));
    }
}

// 再帰により階乗計算を行う関数
long factorial(int n) {

    if(n == 0) {
        return 1L;
    } else {
        return n * factorial(n-1);
    }
}
