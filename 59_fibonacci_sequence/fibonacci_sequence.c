#include <stdio.h>

long fibonacci(long);

void main(void) {

    // フィボナッチ数列の第20項まで計算
    for(long n=1; n<=20; n++) {
        printf("%3ld: %ld\n", n, fibonacci(n));
    }
}

long fibonacci(long n) {

    long a, b, tmp;
    
    a = 1L;  // 第1項
    b = 1L;  // 第2項

    for(int k=3; k<=n; k++) {  // 第3項以降を計算
        tmp = b;               // bの一時保存 (次項でのaとする為)
        b = a + b;             // bを更新 = 求める項の値
        a = tmp;               // 前のbを次項でのaとする
    }
    return b;
}
