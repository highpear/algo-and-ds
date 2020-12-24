#include <stdio.h>

#define LIMIT 8  // ナップサックのサイズ
#define N 5      // 品物の種類
#define MIN 1    // 品物のサイズの最小値

void main(void) {

    // 品物のデータを管理する構造体の配列
    struct body {
        char name[20];  // 品名
        int size;       // 品物のサイズ
        long price;     // 価格
    } data[] = {{"plum",       4, 4500},
                {"apple",      5, 5700},
                {"orange",     2, 2250},
                {"strawberry", 1, 1100},
                {"melon",      6, 6700}};

    long newvalue;        // 新たな条件下での最適解の候補 (=価格)
    long value[LIMIT+1];  // 各ナップサックサイズにおける最適解を記録する配列 (インデックスとサイズが対応)
    int item[LIMIT+1];    // 各ナップサックサイズに最後に入れた品物の番号の配列 (インデックスとサイズが対応)
    int n_size;           // ナップサックのサイズ
    int p;                // ナップサックの空きサイズ

    // 各ナップサックサイズにおける最適解を0で初期化
    for(n_size=0; n_size<=LIMIT; n_size++) {
        value[n_size] = 0;
    }

    // DPを実行
    for(int i=0; i<N; i++) {  // 各品物において以下を実行
        for(n_size=data[i].size; n_size<=LIMIT; n_size++) {  // ナップサックのサイズを増やしていく
            p = n_size - data[i].size;             // 現在の品物を考慮した空きサイズを計算
            newvalue = value[p] + data[i].price;   // 空きサイズにおける最適解と現在の品物の価格から最適解候補を導出
            // 最適解の更新判定
            if(newvalue > value[n_size]) {  // 新たに導出した価格の方が高ければ最適解を更新
                value[n_size] = newvalue;   // 現在のナップサックサイズにおける価格を最適解で更新
                item[n_size] = i;           // 現在のナップサックサイズで新たに加えた品物を記録
            }
        }
    }

    // 結果の出力
    printf("      品目  価格\n");    
    for(n_size=LIMIT; n_size>=MIN; n_size=n_size-data[item[n_size]].size) {  // 各サイズで新たに加えた品物を順に出力
                                                                             // 即ち，出力した品物を差し引いたサイズにおける最適解を順に出力
        printf("%10s %5ld\n", data[item[n_size]].name, data[item[n_size]].price);  // 品物 価格
    }
    printf("      合計 %5ld\n", value[LIMIT]);  // 合計金額はナップサックサイズ8(=LIMIT)における配列valueの値
}
