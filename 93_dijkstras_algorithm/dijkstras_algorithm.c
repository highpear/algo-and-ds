#include <stdio.h>
#include <stdlib.h>

#define N 8     // 節点の数
#define M 9999  // 連結していない節点間の重みに用いる大きな値

int a[N+1][N+1] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},  // 隣接行列
                   {0, 0, 1, 7, 2, M, M, M, M},
                   {0, 1, 0, M, M, 2, 4, M, M},
                   {0, 7, M, 0, M, M, 2, 3, M},
                   {0, 2, M, M, 0, M, M, 5, M},
                   {0, M, 2, M, M, 0, 1, M, M},
                   {0, M, 4, 2, M, 1, 0, M, 6},
                   {0, M, M, 3, 5, M, M, 0, 2},
                   {0, M, M, M, M, M, 6, 2, 0}};

void main(void) {

    int p, start, min,
        leng[N+1],   // 始点から各節点までの最小距離
        v[N+1],      // 確定フラグ (添字に対応する節点は確定済み)
        index[N+1];  // 前の節点へのポインタ (添字とその要素が，節点の番号とその1つ前の節点の番号に対応)

    // 始点とする節点の設定
    printf("start >>");
    scanf("%d", &start);
    
    // 初期化
    for(int k=1; k<=N; k++) {
        leng[k] = M;  // 全てMで初期化
        v[k] = 0;     // 未確定で初期化
    }
    leng[start] = 0;   // 始点から始点への距離はゼロ
    index[start] = 0;  // 始点はどこも示さない

    // ダイクストラ法により，始点から各節点jへの最短距離を求める
    for(int j=1; j<=N; j++) {

        // 最小の節点を探す
        min = M;
        for(int k=1; k<=N; k++) {
            if(v[k] == 0 && leng[k] < min) {  // 未確定の節点，かつ現在の最小値より小さい
                p = k;          // 最初の節点の番号を記録
                min = leng[k];  // 最小値を記録
            }
        }
        v[p] = 1;  // 最小の節点を確定とする

        if(min == M) {  // 最小値がMをとる場合，グラフは連結していない (経路が存在しない)
            printf("error\n");
            exit(1);
        }

        // 確定された節点pを経由し，節点kに至る長さがそれまでの最短路より小さければ更新
        for(int k=1; k<=N; k++) {
            if((leng[p] + a[p][k]) < leng[k]) {
                leng[k] = leng[p] + a[p][k];  // 最短距離を更新
                index[k] = p;                 // 節点kの1つ前が節点pであることを記録
            }
        }
    }

    // 最短距離と経路の出力
    for(int j=1; j<=N; j++) {

        printf("distance:%2d | (destination) [%d]", leng[j], j);    // 最短距離: | 目的地
        p = j;  // 目的地から逆順に辿る
        while(index[p] != 0) {  // 要素が0の節点は始点
            printf(" <- [%d]", index[p]);
            p = index[p];  // 出力した節点を添字とする要素が1つ前の節点を示す
        }
        printf("\n");
    }
}
