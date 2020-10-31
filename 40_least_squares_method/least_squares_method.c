#include <stdio.h>
#include <math.h>

#define N 7   // 与えるデータ数
#define M 5   // M次の項の係数(a_M)まで求める 係数行列のサイズは(M+1)x(M+2)となる

void print_matrix(double array[M+1][M+2]);

void main(void) {

    // 与えるデータ
    double x[] = {-3, -2, -1,  0, 1, 2, 3},  // x座標と
           y[] = { 5, -2, -3, -1, 1, 4, 5};  // それに対応するy座標
    
    double a[M+1][M+2],  // 式(4)の係数行列を表す配列
           s[2*M+1],     // 式(3)における s_u の値を格納する配列
           t[M+1];       // 式(3)における t_v の値を格納する配列

    int i, j, k;
    double p, d, px;

    // 配列 s,t をゼロ埋め
    for(i=0; i<=2*M; i++) {
        s[i] = 0;
    }
    for(i=0; i<=M; i++) {
        t[i] = 0;
    }

    // s_u, 及び t_v を求める
    for(i=0; i<N; i++) {
        for(j=0; j<=2*M; j++) {                 // s_0, s_1, ..., s_2m を導出
            s[j] = s[j] + pow(x[i], j);         // 式(3)における計算
        }
        for(j=0; j<=M; j++) {                   // t_0, t_1, ..., t_m を導出
            t[j] = t[j] + pow(x[i], j) * y[i];  // 式(3)における計算
        }
    }

    // 求めた s_u, t_v の値を係数行列にセットする 
    for(i=0; i<=M; i++) {  // 係数行列の各行に対して
        for(j=0; j<=M; j++) {
            a[i][j] = s[i+j];  // s_u の値を代入．式(4)より係数行列のi行j列成分は，1次元配列sの(i+j)番目要素に該当
        }
        a[i][M+1] = t[i];      // t_v の値を係数行列の右端列へ代入
    }


    // --- 以下，ガウス・ジョルダン法にて掃き出しを行う ---
        // ガウス・ジョルダン法の詳細は 36_gauss_jordan_elimination へ


    for(k=0; k<=M; k++) {

        p = a[k][k];
        for(j=k; j<=M+1; j++) {
            a[k][j] = a[k][j] / p;
        }
        for(i=0; i<=M; i++) {
            if(i != k) {
                d = a[i][k];
                for(j=k; j<=M+1; j++)
                    a[i][j] = a[i][j] - d * a[k][j];
            }
        }
    }


    // --- 掃き出し ここまで ---

    // 以下，結果の出力
    printf("掃き出しが完了\n");
    print_matrix(a);

    // 導出された近似式を用いて，与えられていない点を含む点を x = -3 から x = 3 まで0.5刻みで表示
    printf("\n近似多項式を用いてプロット\n");
    printf("    x    y\n");        // 補間多項式によるｙの値の計算
    for(px=-3; px<=3 ; px=px+0.5) {
        p = 0;
        for(k=0; k<=M; k++) {  // M次の項まで計算
            p = p + a[k][M+1] * pow(px,k);  // 求められた多項式の係数を用いてy座標を導出
        }

        printf("%5.1f%5.1f\n", px, p);
    }

    // 求めらた係数a_mを表示
    printf("\n各係数の値\n");
    for(k=0; k<=M; k++) {
        printf("a_%d = %f\n", k, a[k][M+1]);
    }

    // 求められた近似式の形式で表示
    printf("\n近似多項式:\n");
    printf("f(x) = ");
    for(k=0; k<=M; k++) {
        printf("{ %fx^(%d) } ", a[k][M+1], k);
        if(k < M) {
            printf("+ ");
        }
    }
    printf("\n");

}

// サイズ(M+1)x(M+2)の2次元配列を格子状に表示する関数
void print_matrix(double array[M+1][M+2]) {
    printf(" -- -- -- -- -- -- -- -- -- -- -- - -- -- -- -- -- -- -- -- -- --\n");
    for(int i=0; i<M+1; i++) {
       printf("|");
        for(int j=0; j<M+2; j++) {
            if(array[i][j] > 0) {  // 値が正の場合はマイナスの符号分だけ余白をとる
                printf(" ");
            }
             printf(" %.3f ", array[i][j]);
             if(j == M) {
                 printf("||");  // 解が求まる最後列を強調する
             } else {
                 printf(" |");
            }
        }
        printf("\n");
        printf(" -- -- -- -- -- -- -- -- -- -- -- - -- -- -- -- -- -- -- -- -- --\n");
    }
}