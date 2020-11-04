#include <stdio.h>
#include <stdlib.h>

#define N 9  // ソート対象の要素数

void print_array(int array[], int n);
void shell_sort(int array[], int n);

void main(void) {

    // ソートする配列
    int a[] = {3, 5, 6, 9, 2, 7, 8, 10, 4};

    // 配列の表示
    printf("ソート前:\n");
    print_array(a, N);

    // 挿入ソートの実行
    shell_sort(a, N);

    // 配列の表示
    printf("ソート済:\n");
    print_array(a, N);

}

// 配列の全要素を表示する関数 
void print_array(int array[], int n) {

    for(int i=0; i<n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void shell_sort(int array[], int n) {
    
    int gap, tmp;

    gap = N / 2;  // gapの初期値をデータ数の半分(9/2 = 4.5 -> 4)とする
    
    while(gap > 0) {  // gap = 1 になるまで繰り返す

        for(int k=0; k<gap; k++) {  // gapとびの部分数列は全部でgap個，それらすべてに以下を適用
            for(int i=k+gap; i<N; i=i+gap) {  // 配列のindexがオーバーフローしないようにgapずつずらす
                for(int j=i-gap; j>=k; j=j-gap) {  // kが同じグループの要素(=gapだけずれて隣り合う要素)を順に比較していく
                    if(array[j] > array[j+gap]) {
                        // 前の要素 < 後の要素 となるように交換 (gap分に注意)
                        tmp = array[j];
                        array[j] = array[j+gap];
                        array[j+gap] = tmp;
                    } else {
                        break;
                    }
                }
            }
        }
        gap = gap / 2;  // gapを半分にする
    }
}

