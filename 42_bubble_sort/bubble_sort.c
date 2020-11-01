#include <stdio.h>

#define N 6  // ソート対象の要素数

void print_array(int array[], int n);
void bubble_sort(int array[], int n);

void main(void) {

    // ソートする配列
    int a[] = {80, 41, 35, 90, 40, 20};

    // 配列の表示
    printf("ソート前:\n");
    print_array(a, N);

    // バブルソートの実行
    bubble_sort(a, N);

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

// int型配列をバブルソートで昇順ソートする関数
void bubble_sort(int array[], int n) {

    int tmp;

    for(int i=0; i<n-1; i++) {
        for(int j=n-1; j>i; j--) {       // 配列を後ろから順に見る
            if(array[j-1] > array[j]) {  // 前の要素 > 後の要素
                
                // 後が前より小さければ，前後の要素を交換 (昇順=前側が小さい)
                tmp = array[j];
                array[j] = array[j-1];
                array[j-1] = tmp;
            }
        }
    }
}
