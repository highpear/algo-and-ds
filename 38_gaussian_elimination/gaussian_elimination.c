#include <stdio.h>

#define N 3  // N元1次連立方程式の解を求める

void print_matrix(double array[N][N+1]);

void main(void) {
    
    // 拡大係数行列を表す2次元配列
    double a[N][N+1] = {{ 2.0, 3.0,  1.0,  4.0},
                        { 4.0, 1.0, -3.0, -2.0},
                        {-1.0, 2.0,  2.0,  2.0}};
    double d;
    int i,j,k;


    // 過程を画面出力①
    printf("拡大係数行列の初期状態\n");
    print_matrix(a);
    printf("\n");
    // 過程を画面出力① ここまで


    // 前進消去を実行
    for(k=0; k<N-1; k++) {  // ピボットを対角に移動
        for(i=k+1; i<N; i++) {
            
            d = a[i][k] / a[k][k];
    
            for(j=k+1; j<=N; j++) {
                a[i][j] = a[i][j] - a[k][j] * d;  // 第i行 - 第k行 * d
            }
        }
    }


    // 過程を画面出力②
    printf("前進消去が完了\n");
    print_matrix(a);
    printf("\n");
    // 過程を画面出力② ここまで


    // 後退代入を実行
    for(i=N-1; i>=0; i--) {  // b_N', ..., b_1'の順に処理
        
        d = a[i][N];         // b_i' の値をコピー

        for(j=i+1; j<N; j++) {  // 縦ベクトルBのより大きなj行成分について以下を適用 (※初回 b_i'=b_N' は以降のBの成分が無い為，以下の処理はスキップされる)

            d = d - a[i][j] * a[j][N];  // b_i'(=d) から Bの(i+1)行以降成分とそれに対応する同i行のaの各成分の積を引いていく

        }

        // 過程を画面出力③
        printf("<後退代入>\n");
        printf("縦ベクトルの成分 b_(%d)'について:\n", i+1);
        printf("a_(ij)' * b_j'を減算する処理が完了\n");
        print_matrix(a);
        printf("\n");
        // 過程を画面出力③ ここまで
        
        a[i][N] = d / a[i][i];  // 先のdをa_(ii)'で除して解 x_i を求める (後退代入により x_N, ..., x_1 の順に求められる)

        // 過程を画面出力④
        printf("a_(ii)'で除してb_(%d)'が導出完了\n", i+1);
        print_matrix(a);
        printf("\n");
        // 過程を画面出力④ ここまで

    }

    printf("最終的な拡大係数行列a\n");
    print_matrix(a);
    printf("\n");

    // 解の出力 (拡大係数行列におけるN+1列目の全要素)
    printf("解\n");
    for(k=0; k<=N-1; k++) {
        printf("x_%d = %f\n", k+1, a[k][N]);
    }
}

// サイズNx(N+1)の2次元配列を格子状に表示する関数
void print_matrix(double array[N][N+1]) {

    printf(" -- -- -- -- -- -- -- -- -- -- -- --\n");

    for(int i=0; i<N; i++) {
        printf("|");
        
        for(int j=0; j<N+1; j++) {

            if(array[i][j] > 0) {  // 値が正の場合はマイナスの符号分だけ余白をとる
                printf(" ");
            }

            printf(" %.2f ", array[i][j]);

            if(j == N-1) {
                printf("||");  // 解が求まる最後列を強調する
            } else {
                printf(" |");
            }

        }
        printf("\n");
        printf(" -- -- -- -- -- -- -- -- -- -- -- --\n");
    }
}