#include <stdio.h>

long fibonacci(long n);

void main(void) {

    long n;
    
    // フィボナッチ数列の第20項まで計算
    for(n=1; n<=20; n++) {
        printf("%3ld: %ld\n", n, fibonacci(n));
    }
}

// 再帰を用いてフィボナッチ数列の項を計算する関数
long fibonacci(long n) {

    if(n==1 || n==2) {
        return 1L;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
