#include <stdio.h>
#include <math.h>

#define M 4      // 行数 (制約式+目的関数)
#define N 6      // 列数
#define X_NUM 2  // 変数の数 x_1, x_2 の2つ

void print_matrix(double array[M][N]);

void main(void) {

    // 制約式，及び目的関数から得られた係数行列
    double a[M][N] = {{ 1.0,  2.0, 1.0, 0.0, 0.0, 14.0},   // <- 材料Aによる制約より
                      { 1.0,  1.0, 0.0, 1.0, 0.0,  8.0},   // <- 材料Bによる制約より
                      { 3.0,  1.0, 0.0, 0.0, 1.0, 18.0},   // <- 材料Cによる制約より
                      {-2.0, -3.0, 0.0, 0.0, 0.0,  0.0}};  // <- 目的関数より
    double min, p, d;
    int j, k, x, y, flag;

    printf("係数行列の初期状態\n");
    print_matrix(a);
    printf("\n");

    while(1) {  // 最下行の成分が全て正になるまでループ

        min = 9999;  // 最小値を適当に大きな値で初期化
        
        // 列選択
        for(k=0; k<N-1; k++) {  // 最下行の成分から最小値を見つける

            if(a[M-1][k] < min) {
            
                min = a[M-1][k];
                y = k;  // 最小値が存在する列を取得
            }
        }

        if(min >= 0) {  // 最下行全ての要素が正になれば終了
            break;
        }

        min = 9999;           
        
        // 行選択
        for(k=0; k<M-1; k++) {  // 選択したy列の各行について

            p = a[k][N-1] / a[k][y];  // 右端要素を，選択した列の同じ行要素で割る
            
            if(a[k][y]>0 && p<min) {  // pの最小値を求める
                
                min = p;  // 最小値を更新
                x = k;    // 最小値が存在する行を取得
            }
        }

        p = a[x][y];   // x行y列からピボット係数を取得



        // --- 以下，ガウス・ジョルダン法にて掃き出しを行う ---
            // ガウス・ジョルダン法の詳細は 36_gauss_jordan_elimination へ

        for(k=0; k<N; k++) {  
            a[x][k] = a[x][k] / p;
        }

        for(k=0; k<M; k++) {
            if(k != x) {
                d = a[k][y];
                for(j=0; j<N; j++) {
                    a[k][j] = a[k][j] - d * a[x][j];
                }
            }
        }

        // 掃き出しの過程を出力 
        printf("掃き出し中...\n");
        print_matrix(a);
        printf("\n");
    }

    printf("掃き出しが完了\n");
    print_matrix(a);
    printf("\n");

    // 解 x_1, x_2の抽出
    for(k=0; k<X_NUM; k++) {  // 係数行列のうち，パラメータx_1, x_2の係数に該当する列(つまり1列目と2列目)のみ調べる

        flag = -1;  // 成分が1となる行を見つけたらその行を代入するフラグ

        for(j=0; j<M; j++) {  // j行目の成分を順次調べる
            if(a[j][k] == 1) {
                flag = j;     // 1を見つけたらその行を記録 
            }
        }

        if(flag != -1) {  // 1を発見済み (フラグの値は1が存在する行番号)
            printf("x_%d = %f (%d行%d列)\n", k+1, a[flag][N-1], flag+1, N);  // 最適解は同行右端列成分
        } else {  // 1が見つからない場合
            printf("x_%d = %f\n", k+1, 0.0);
        }
    }

    // 目的関数の最適解(z = 2x_1 + 3x_2)はM行N列目に格納されている
    printf(" z  = %f\n", a[M-1][N-1]);
}

// サイズMxNの2次元配列を格子状に表示する関数
void print_matrix(double array[M][N]) {

    printf(" -- -- -- -- -- -- -- -- -- -- -- - -- -- -- -- -- --\n");

    for(int i=0; i<M; i++) {
        printf("|");
        
        for(int j=0; j<N; j++) {

            if(array[i][j] > 0) {  // 値が正の場合はマイナスの符号分だけ余白をとる
                printf(" ");
            }

            printf(" %.2f ", array[i][j]);

            if(j == N-2) {
                printf("||");  // 解が求まる最後列を強調する
            } else {
                printf(" |");
            }

        }
        printf("\n");
        printf(" -- -- -- -- -- -- -- -- -- -- -- - -- -- -- -- -- --\n");
    }
}