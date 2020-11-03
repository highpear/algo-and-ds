#include <stdio.h>
#include <stdlib.h>

#define N 9  // ソート対象の要素数

void print_array(int array[], int n);
void insertion_sort(int array[], int n);

void main(void) {

    // ソートする配列
    int a[] = {3, 5, 6, 9, 2, 7, 8, 10, 4};

    // 配列の表示
    printf("ソート前:\n");
    print_array(a, N);

    // 挿入ソートの実行
    insertion_sort(a, N);

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

// int型配列を挿入ソートで昇順ソートする関数
void insertion_sort(int array[], int n) {

    int tmp;

    // --> --> iの走査方向 --> -->
    for(int i=1; i<N; i++) {  // 初期状態：[0]はソート済み
        // <-- <-- j の走査方向 <-- <--
        for(int j=i-1; j>=0; j--) { // [i]より前の要素を1つずつ比較
            if(array[j] > array[j+1]) {
                // 前の要素 < 後の要素 となるように交換
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
            else {  // 即座に i を更新する為 break
                break;
            }
        }
    }
}
