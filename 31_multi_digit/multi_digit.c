#include <stdio.h>

#define DIGITS 20           // 桁数
#define N ((DIGITS-1)/4+1)  // 計算に用いる配列のサイズ

void long_add(short *, short *, short *);
void long_sub(short *, short *, short *);
void print(short *);

void main(void) {

    // ロング数の配列をshort型の配列で扱う
    short a[N+2] = {1999, 4444, 7777, 2222, 9999},
          b[N+2] = { 111, 6666, 3333, 8888, 1111},
          c[N+2];  // 計算結果を格納

    printf("a = ");
    print(a);
    printf("b = ");
    print(b);
    printf("\n");

    // a+bを実行
    long_add(a, b, c);
    printf("a + b = ");
    print(c);
    
    // a-bを実行
    long_sub(a, b, c);
    printf("a - b = ");
    print(c);
}

// 配列を用いてロング数の加算を行う関数
void long_add(short a[], short b[], short c[]) {

    short cy = 0;  // キャリーをゼロで初期化
    
    for(short i=N-1; i>=0; i--) {
        
        c[i] = a[i] + b[i] + cy;        
        
        if (c[i] < 10000) {
            cy=0;
        } else {  // 加算して繰り上がる場合
            c[i] = c[i] - 10000;  // 繰り上げ分を引く
            cy = 1;  // 繰り上げ分を次の桁の計算に使用
        }
    }
}

// 配列を用いてロング数の減算を行う関数
void long_sub(short a[], short b[], short c[]) {

    short brrw = 0;  // ボロ―(借り)をゼロで初期化

    for(short i=N-1;i>=0;i--) {
        
        c[i] = a[i] - b[i] - brrw;
        
        if(c[i] >= 0) {
            brrw=0;
        } else {  // 減算して負になる場合
            c[i] = c[i] + 10000;  // 繰り下がり分を加える
            brrw = 1;  // 繰り下がり分を次の桁の計算に使用
        }
    }
}

// ロング数の表示を行う関数
void print(short c[]) {

    for(short i=0; i<N; i++) {
        printf("%04d ", c[i]);
    }
    printf("\n");
}
