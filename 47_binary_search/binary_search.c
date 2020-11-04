#include <stdio.h>

#define N 10  // 探索対象のデータの要素数

void main(void) {

    int a[] = {2, 3, 7, 11, 31, 50, 55, 70, 77, 80};
    int key, low, high, mid, flag=0;

    // 探索する整数値を入力
    printf("Number? >>");
    scanf("%d", &key);
    
    // 探索範囲の初期化
    low = 0;
    high = N-1;

    // 2分探索の実行
    while(low <= high) {  // 探索範囲が存在する限り繰り返す
        
        mid = (low + high) / 2;  // 探索範囲を2分する中央のindexを求める
        
        if(a[mid] == key) {  // [mid] において key を発見した場合
            printf("%d is at [%d]\n", a[mid], mid);
            flag = 1;  // 発見を記録
            break;
        }

        // ||    [low]    | mid |    [high]    ||
        //     ↑                  ↑
        //    key (case 2)         key (case 1)

        if(a[mid] < key) {   // (case 1) key が2分した範囲の大きい方にある時
            low = mid + 1;   // 探索範囲を大きい方に更新
        } else {             // (case 2) key が2分した範囲の小さい方にある時
            high = mid - 1;  // 探索範囲を小さい方に更新
        }
    }

    // 一致なしの場合のみ以下を出力
    if(flag != 1) {
        printf("Not found\n");
    }
}
