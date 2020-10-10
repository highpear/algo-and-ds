#include <stdio.h>

#define DATA_NUM 20 // 元のデータの個数

void main(void) {

    int score[] = {35,25,56,78,43,66,71,73,80,90,
                0,73,35,65,100,78,80,85,35,50};  // 20人分の試験の点数
    
    int rank, histogram[11];

    // ヒストグラムの配列をゼロで初期化
    for (int i=0; i<=10; i++) {
        histogram[i] = 0;
    }

    // 写像を行う(ヒストグラムの作成)
    for (int i=0; i<DATA_NUM; i++){
        
        rank = score[i] / 10;     // 対応するヒストグラムの配列のインデックスを求める

        if (0<=rank && rank<=10)  // インデックスのオーバーフローをチェック
            histogram[rank]++;    // 度数をカウント(インクリメント)
    }

    // ヒストグラムを表示
    for (int i=0; i<=10; i++) {
        printf("%3d点 -  :%3d人\n", i*10, histogram[i]);
    }
}