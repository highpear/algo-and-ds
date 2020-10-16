#include <stdio.h>
#include <math.h>

#define NUM 1000  // 1000以下の素数を全て列挙する

int is_prime(int);

void main(void) {

    int prime[NUM/2+1];  // 素数を保存する配列，存在し得る素数の分だけ確保
    int idx = 0;         // 配列primeのindexに使用

    for (int n=2; n<=NUM; n++){

        int result = is_prime(n);  // 素数判定を行う
        // 素数であれば配列に追加
        if(result == 1) {
            prime[idx++] = n;
        }
    }

    // 結果の出力
    printf("\nprime numbers are...\n");
    for (int i=0; i<idx; i++) {
        printf("%5d", prime[i]);
    }
    printf("\n");
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