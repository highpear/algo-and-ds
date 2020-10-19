#include <stdio.h>

#define N 1000          // 乱数の発生回数
#define M 10            // 整数乱数の範囲
#define F (N/M)         // 期待値
#define SCALE (40.0/F)  // ヒストグラムの高さ (自動スケール)

unsigned rndnum = 13;   // 乱数の初期値

unsigned irnd(void);
double rnd(void);

void main(void) {

    int rank;       // ヒストグラムの階級
    int hist[M+1];  // ヒストグラムの配列
    double e = 0.0;

    // ヒストグラムの初期化
    for (int i=1; i<=M; i++) {
        hist[i] = 0;
    }

    // 乱数を発生させ，配列の対応する要素をインクリメント
    for (int i=0; i<N; i++) {
        rank = (int)(M*rnd()+1);  // 1～Mの乱数を1つ発生
        hist[rank]++;
    }

    for (int i=1; i<=M; i++) {  
        printf("%3d:%3d ", i, hist[i]);        // 「乱数：度数」で表示
        for (int j=0; j<hist[i]*SCALE; j++) {  // ヒストグラムの表示
            printf("□");
        }
        printf("\n");

        e = e+(double)(hist[i]-F)*(hist[i]-F)/F;  // χ2の計算
    }

    printf("χ^2 = %f\n", e);                      // χ2の値を表示 
}

// 0～32767の整数乱数を発生させる
unsigned irnd(void) {
    rndnum = (rndnum*109+1021) % 32768;
    return rndnum;
}

// 0～1(未満)の実数乱数を発生させる
double rnd(void) {
    return irnd()/32767.1;
}
