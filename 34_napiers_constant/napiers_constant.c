#include <stdio.h>

void long_add(short *, short *, short *);
void long_div(short *, short, short *);
void print_result(short *);

#define L 1000        // 求める桁数
#define L1 ((L/4)+1)  // 計算に用いる配列のサイズ
#define L2 (L1+1)     // +1のサイズ
#define N 451         // 第N項まで計算

void main(void) {

    short s[L2+2], w[L2+2];

    // 全配列をゼロ埋め
    for(short k=0; k<=L2; k++) {
        s[k] = w[k] = 0;
    }

    // 第0項の値を設定
    s[0] = w[0] = 1;

    for(short k=1; k<=N; k++) {  // 第k項まで加算した結果をsに保存していく (第1項は1/1!の項)
        long_div(w, k, w);       // w/k -> w wは第k項の値 (逐次階乗を計算せずとも更新前のwは前項の値であるから現在のkで割るだけで良い)
        long_add(s, w, s);       // s+w -> s sは第k項まで加算した値
    }

    // 求めたeの値を表示
    print_result(s);
}

// 配列形式のロング数を表示する関数
void print_result(short c[]) {
    
    printf("%3d. ", c[0]);       // 最上位桁の表示
    for(short i=1; i<L1; i++) {  // 小数点以下の表示
        printf("%04d ", c[i]);
    }
    printf("\n");
}

// 以下，配列を用いてロング数の加算，及び除算を行う関数 (前章から流用)

void long_add(short a[], short b[], short c[]) {

    short cy = 0;
    for(short i=L2; i>=0; i--) {
        c[i] = a[i] + b[i] + cy;
        if(c[i] < 10000) {
            cy = 0;
        } else {
            c[i] = c[i] - 10000;
            cy = 1;
        }
    }
}

void long_div(short a[], short b, short c[]) {
    
    long d, rem = 0;
    for(short i=0; i<=L2; i++) {
        d = a[i];
        c[i] = (short)((d + rem) / b);
        rem = ((d + rem) % b) * 10000;
    }
}
