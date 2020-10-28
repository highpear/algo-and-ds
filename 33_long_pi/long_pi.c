#include <stdio.h>

void long_add(short *, short *, short *);
void long_sub(short *, short *, short *);
void long_div(short *, short, short *);
void print_result(short *);

#define L 1000                  // 求める桁数
#define L1 ((L/4)+1)            // 計算に用いる配列のサイズ
#define L2 (L1+1)               // +1のサイズ
#define N (short)(L/1.39794+1)  // N項まで計算

void main(void) {

    short s[L2+2], w[L2+2], v[L2+2], q[L2+2];

    // 全配列をゼロ埋め
    for(short k=0; k<=L2; k++) {
        s[k] = w[k] = v[k] = q[k] = 0;        
    }

    w[0] = 16 * 5;   // 漸化式におけるw_0を計算
    v[0] = 4 * 239;  // 漸化式におけるv_0を計算

    for(short k=1; k<=N; k++) {   // マチンの公式によりπをN桁まで計算

        long_div(w, 25, w);       // 式(8)の()内，左の項における計算 w_n = w_(n-1)/25
        long_div(v, 239, v);      // v_n = v_(n-1)/239 (1回目)
        long_div(v, 239, v);      // 2回目の除算で式(8)の()内，右の項における計算 v_n = v_(n-1)/(239^2)となる
        long_sub(w, v, q);        // q = w - v 式(8)における()内の計算
        long_div(q, 2 * k-1, q);  // q/(2n-1) の計算 (式(8)全体の計算)
        
        // ここで第k項の値が導出済み (符号は次で決定)

        if((k%2) != 0) {      // 奇数項の符号は正
            long_add(s,q,s);  // s += q
        } else {              // 偶数項の符号は負
            long_sub(s,q,s);  // s -= q
        }
    }
    
    // 求めたπの値を表示
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

// 以下，配列を用いてロング数の加減算，及び除算を行う関数 (前前章・前章から流用)

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

void long_sub(short a[], short b[], short c[]) {
    
    short brrw = 0;
    for(short i=L2; i>=0; i--) {
        c[i] = a[i] - b[i] - brrw;
        if(c[i]>=0) {
            brrw = 0;
        } else {
            c[i] = c[i] + 10000;
            brrw = 1;
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
