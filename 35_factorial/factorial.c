#include <stdio.h>

void long_mul(short *, short, short *);
void print_result(short *);

#define N 49          // N!まで求める (最大49を想定)
#define L 64          // 求める桁数
#define L2 ((L+3)/4)  // 計算に用いる配列のサイズ

void main(void) {

    short s[L2];  // 計算結果を格納する配列
    
    // 配列をゼロ埋め
    for(short k=0; k<L2; k++) {
        s[k] = 0;
    }

    // 初期値 (1!)
    s[L2-1] = 1;

    for(short k=1; k<=49; k++) {
        long_mul(s, k, s);  // s*k -> s 即ち s_k = s_(n-1)*k を計算
        // k!を表示   
        printf("%2d! = ", k);
        print_result(s);
    }
}

// ロング数*ショート数の計算を行う関数 (流用)
void long_mul(short a[], short b, short c[]) {
    
    long d, cy = 0;
    for(short i=L2-1; i>=0; i--) {

        d = a[i];
        c[i] = (d * b + cy) % 10000;
        cy = (d *b + cy) / 10000;
    }
}

// ロング数の表示を行う関数
void print_result(short c[]) {
    for(short i=0; i<L2; i++) {
        printf("%04d", c[i]);
    }
    printf("\n");
}
