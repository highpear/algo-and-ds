#include <stdio.h>

#define DIGITS 20           // 桁数
#define N ((DIGITS-1)/4+1)  // 計算に用いる配列のサイズ

void long_mul(short *, short, short *);
void long_div(short *, short, short *);
void print(short *);

void main(void) {

    // ロング数をshort型の配列で扱う
    short a[N+2] = {   0, 3050, 2508, 8080, 1233},
          c[N+2];  // 計算結果を格納

    printf("a = ");
    print(a);
    printf("\n");

    // 乗算を実行
    long_mul(a, 101, c);
    printf("a * 101 = ");
    print(c);

    // 除算を実行    
    long_div(a, 200, c);
    printf("a / 200 = ");
    print(c);
}

// 配列を用いてロング数*ショート数の乗算を行う関数
void long_mul(short a[],short b,short c[]) {

    long d, cy = 0;  // キャリーをゼロで初期化
    
    for(short i=N-1; i>=0; i--) {
        d = a[i];                     // 計算を行う4桁分をコピー
        c[i] = (d * b + cy) % 10000;  // 剰余演算で4桁を超えない値だけ保存
        cy = (d * b+ cy) / 10000;     // 繰り上がり分を更新
    }
}

// 配列を用いてロング数/ショート数の除算を行う関数
void long_div(short a[], short b, short c[]) {
    
    long d, rem = 0;  // 余りをゼロで初期化
    
    for(short i=0; i<N; i++) {
        d = a[i];                       // 計算を行う4桁分をコピー
        c[i] = (short)((d + rem) / b);  // 商を計算して保存
        rem = ((d + rem) % b) * 10000;  // 剰余演算を行って余りを更新
    }
}

// ロング数の表示を行う関数
void print(short c[]) {

    for(short i=0; i<N; i++) {
        printf("%04d ", c[i]);
    }
    printf("\n");
}
