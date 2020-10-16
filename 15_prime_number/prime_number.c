#include <stdio.h>
#include <math.h>

int is_prime(int);

void main(void) {

    int n;
    // 繰り返し整数nの入力を受け付ける
    while (printf("input n (n>=2) >>"), scanf("%d", &n) != EOF) {
        
        int result = is_prime(n);  // 素数か判定
        // 結果の表示
        if (result == 1) {
            printf("%d is prime number\n", n);      // 素数のとき
        } else {
            printf("%d is not prime number\n", n);  // 素数でないとき
        }    
    }
}

// 素数なら1を返す
int is_prime(int n) {

    if(n >= 2) {  // nが2以上のみ計算する
        for(int i=sqrt((double)n); i>1; i--) {  // 開始値を決定 (nの平方根とする)
            if (n%i == 0) {                     // 割り切る数があった時
                return 0;                       // 素数でない
            }
        }
    } else {
        return 0;  // 1以下の整数については0を返すことにする
    }

    return 1;      // ループを抜ければ素数
}